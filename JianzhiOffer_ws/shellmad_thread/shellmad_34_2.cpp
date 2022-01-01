#include <thread>
#include <chrono>
#include <iostream>
#include <mutex>

//timed_mutex 提供了等待超时的机制
//   1) try_lock 避免了阻塞，获取不到锁则直接返回false
//   2) try_lock_for 等待时间
//   3) try_lock_until 等待时间点

using namespace std;

timed_mutex test_mutex;

void f()
{
    auto now = chrono::steady_clock::now();

    // if (test_mutex.try_lock())  //获取不到锁则直接返回false
    if (test_mutex.try_lock_for(chrono::seconds(10)))   //等待10s，10s内尝试获取锁，若获取不到就返回false
    // if (test_mutex.try_lock_until(now + chrono::seconds(10))) //等待点xxx，在时间点xxx内尝试获取锁，若持续获取不到就返回false
    {
        cout << "success!\n";

        test_mutex.unlock();
    }
    else
    {
        cout << "failed!\n";
    }

    cout << "hello world\n";
}

int main()
{
    lock_guard<timed_mutex> l(test_mutex);
    thread t(f);
    t.join();
}