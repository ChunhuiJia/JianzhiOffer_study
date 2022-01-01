// 线程所带来的问题
// c++11的线程同步问题：

#include <iostream>
#include <thread>

using namespace std;

int g_nData = 0;

//高级语言(c/c++) ----->  低级语言(汇编语言)
/*
同时：时间片的交替，在线程1和线程2中间有可能会切换时间片，有可能在线程1运行到第二步时切换到线程2的第三步，类似这样的随机切换
线程1：
    c/c++中的语句 g_nData++; 对应的汇编语言代码（在foo中的g_nData++）：
    008E42D9 mov     eax,dword ptr [g_nData (09EE390h)]  :寄存器eax = 内存中g_nData数值
    008E42DE add     eax,1                               :寄存器eax++
    008E42E1 mov     dword ptr [g_nData (08EE390h)],eax  :内存中g_nData数值 = 寄存器eax

线程2：
    在main中的g_nData++
    00904A4F mov     eax,dword ptr [g_nData (09EE390h)]  :寄存器eax = 内存中g_nData数值
    00904A54 add     eax,1                               :寄存器eax++
    00904A57 mov     dword ptr [g_nData (08EE390h)],eax

    线程间的进程是随机的
*/


void foo()
{
    for (int i = 0; i < 100000; i++)
    {
        //++操作对应的汇编代码不止一行 
        g_nData++;
    }
}

int main(int argc, char *argv[])
{
    thread t(foo);

    for (int i = 0; i < 100000; i++)
    {
        g_nData++;
    }

    t.join();

    cout << g_nData << endl;  //最后结果小于200000,异常，是由于线程间时间片的无规律切换，导致线程中断之后再运行的数据异常

    return 0;
}