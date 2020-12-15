#pragma once

#include <condition_variable>
#include <mutex>
#include <queue>
#include <iostream>

namespace test
{

template <typename T>
class ThreadSafeQueue final
{
public:
    ThreadSafeQueue();

    ~ThreadSafeQueue();

    ThreadSafeQueue(const ThreadSafeQueue& ) = delete;
    ThreadSafeQueue& operator = (const ThreadSafeQueue& ) = delete;

    ThreadSafeQueue(ThreadSafeQueue&& ) = default;
    ThreadSafeQueue& operator = (ThreadSafeQueue&& ) = default;

    inline void push(T&& ptr);

    inline T waitPop();

    inline void stop();

    std::size_t getSize() const;

private:
    bool m_stop{false};
    std::size_t size = 0;
    std::unique_ptr<std::mutex> sync{std::make_unique<std::mutex>()};
    std::unique_ptr<std::condition_variable> m_condVar{std::make_unique<std::condition_variable>()};

    std::queue<T> m_queue;

};

template<typename T>
ThreadSafeQueue<T>::ThreadSafeQueue()
{

}

template<typename T>
ThreadSafeQueue<T>::~ThreadSafeQueue()
{

}

template<typename T>
void ThreadSafeQueue<T>::push(T&& data)
{
    //if (data==T())
    //    return;
    std::lock_guard l(*sync);
    m_queue.push(std::move(data));
    ++size;
    m_condVar->notify_all();
}

template<typename T>
T ThreadSafeQueue<T>::waitPop()
{
    std::unique_lock l(*sync);
    m_condVar->wait(l, [&]{return size>0;});

    --size;

    if (m_stop || m_queue.empty())
        return T();
/*
    if(m_queue.back()==T())
    {
        std::cout << m_queue.back().get() <<std::endl;
        std::cout << m_queue.front().get() <<std::endl;
        return T();
    }
*/
    auto result = std::move(m_queue.front());
    m_queue.pop();
    return result;
}

template<typename T>
void ThreadSafeQueue<T>::stop()
{
    std::lock_guard l(*sync);
    m_stop = true;
    ++size;
    m_condVar->notify_all();
}

template<typename T>
std::size_t ThreadSafeQueue<T>::getSize() const
{
    std::lock_guard l(*sync);
    return size;
}

}
