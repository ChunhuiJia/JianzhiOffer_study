#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int Foo(int a, int b)
{
    return a + b;
}

int main()
{
    //lambda表达式就是匿名函数(没有名字的函数)
    // []代表捕获列表  ()代表参数列表   ->代表返回值类型
    int c = [](int a, int b) -> int {
        //函数体
        return a + b;
    }(1, 2); //(1,2)传参直接调用该匿名函数，等同于调用 int c = Foo(1,2);

    cout << c << endl;

    //上述定义匿名函数的时候因为没有函数名，只能在写匿名函数的时候就进行调用，不能重复使用
    //为了解决这个问题，可以理解函数体的主体可以存储起来，存储的类型是auto，用auto自动类型推导匿名函数的类型
    auto f = [](int a, int b) -> int {
        //函数体
        return a + b;
    };

    int d = f(2, 3);
    cout << d << endl;

    //lambda表达式可以内部嵌套
    // 函数式编程 多线程，并发可以避免多线程同步问题
    int e = [](int n) {
        return [n](int x) { //[n]是捕获列表，表示n才可以在第二层匿名函数的表达式里使用
            return n + x;
        }(1); //(1)表示 x=1
    }(2);     //(2)表示 n=2

    cout << e << endl;

    auto ef = [](int n) {
        return [n](int x) {
            return n + x;
        };
    };

    int result_f = ef(3)(4);   //n=3,x=4

    cout << result_f << endl;

    return 0;
}