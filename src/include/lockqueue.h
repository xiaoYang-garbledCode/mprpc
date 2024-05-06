#pragma once
#include<queue>
#include<condition_variable>
#include<mutex>
// 线程安全的queue队列
template<typename T>
class lockQueue
{
public:
    // 将日记信息放入队列
    void Push(const T &val)
    {
        // 拿到锁
        std::lock_guard<std::mutex> lock(mtx_);
        // 将val放入队列
        queue_.push(val);
        // 通知写线程
        cond_.notify_one();
    }
    // 从日志队列取日志，(之后写入磁盘)
    T Pop()
    {
        // 拿到锁
        std::unique_lock<std::mutex> lock(mtx_);
        // 判断队列是否为空
            // 队列为空，wait，进入等待状态，释放抢到的锁，等待notify变为阻塞，抢到锁再变为就绪
        // 在等待期间还是要持续判断队列是否为空
        while(queue_.empty())
        {
            cond_.wait(lock);
        }
        // 取队首元素返回
        T val = queue_.front();
        // 首元素出队
        queue_.pop();
        return val;
    }


private:
    std::condition_variable cond_;
    std::queue<T> queue_;
    std::mutex mtx_;
};