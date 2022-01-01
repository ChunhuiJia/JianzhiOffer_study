// c++11中的线程 对不同的系统的多线程做了统一的语法环境

#include <iostream>
#include <thread>

using namespace std;

void foo()
{
    cout << "hello world" << endl;
}

int main(int argc, char *argv[])
{
    thread t(foo);  //创建一个线程对象，foo是线程里运行的回调函数

    t.join();  //等待子线程t的运行结束

    return 0; 
}