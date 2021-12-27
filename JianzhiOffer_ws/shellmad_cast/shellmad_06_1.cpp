//
#include <iostream>
#include <cstring>

//test1:常量对象或者是基本数据类型不允许转化为非常量对象，只能通过指针或者引用来修改：
void test1()
{
    const int n = 5;
    const std::string s = "Inception";

    //const_cast 只针对指针，引用，this指针
    // std::string t = const_cast<std::string>(s); //错误
    // int k = const_cast<int>(n);                 //错误
    int *k = const_cast<int *>(&n); //正确
    *k = 123;
    int &kRef = const_cast<int &>(n); //正确
    kRef = 456;

    // n = 10; //错误,n 没有被去除，去除const属性的是转换之后的*k和kRef
}

//test2: 常成员函数中去除this指针的const属性
class CTest
{
public:
    CTest() : m_nTest(2) {}
    void foo(int nTest) const  // const常成员函数，不能修改成员变量的值
    {
        //m_nTest = nTest;  //在常成员函数内直接修改成员变量  会报错误
        const_cast<CTest *>(this)->m_nTest = nTest;  //通过const_cast去除this指针的const属性
    }

public:
    int m_nTest;
};

int main(int argc, char *argv[])
{
    // int n = 1;
    // int *p = (int *)n; //转换为ox1这个地址，一般是不可写的
    // *p = 1;            // 会报错

    test1();

    //test2
    CTest t;
    t.foo(1);

    return 0;

    // 基类----->派生类，可能也会访问出错

    // 函数指针的转换，可能也会出错

    // 在C语言，这些都是需要程序员自己负责确定是否正确的
}
