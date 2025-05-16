#include "gtest/gtest.h"
#include <thread>
#include <chrono>
#include <shared_mutex>

void thread_func(std::shared_timed_mutex& mtx)
{
    std::unique_lock<std::shared_timed_mutex> lock2(mtx);
    std::this_thread::sleep_for(std::chrono::seconds(2));
}

[[nodiscard]]
std::thread get_lock(std::shared_timed_mutex& mtx)
{
    std::thread t1(thread_func, std::ref(mtx));
    std::this_thread::sleep_for(std::chrono::milliseconds(1)); //wait for thread_func to get lock
    return t1;
}

TEST(testcpp14, test_lock)
{
    {
        std::shared_timed_mutex mtx;
        std::shared_lock<std::shared_timed_mutex> lock(mtx); 
        EXPECT_TRUE(lock.owns_lock());
    }
    {
        std::shared_timed_mutex mtx;
        std::thread t1 = get_lock(mtx);
        std::shared_lock<std::shared_timed_mutex> lock(mtx, std::try_to_lock);
        EXPECT_FALSE(lock.owns_lock());
        t1.join();
    }
    {
        std::shared_timed_mutex mtx;
        std::thread t1 = get_lock(mtx);
        std::shared_lock<std::shared_timed_mutex> lock(mtx, std::chrono::seconds(1));
        EXPECT_FALSE(lock.owns_lock());
        t1.join();
    }
    {
        std::shared_timed_mutex mtx;
        std::thread t1 = get_lock(mtx);
        std::shared_lock<std::shared_timed_mutex> lock(mtx, std::chrono::seconds(3));
        EXPECT_TRUE(lock.owns_lock());
        t1.join();
    }
}