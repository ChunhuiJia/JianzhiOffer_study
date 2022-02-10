

#include <iostream>

class CInteger
{
public:
    CInteger(int nNumber)
    {
        m_nNumber = nNumber;
    }

    int GetNumber() const;
    void SetNumber(int nNumber)
    {
        m_nNumber = nNumber;
    }

    // 静态成员函数
    // （1） 在头文件的函数名前面加上关键字static
    // （2） 函数内部不能够访问非静态成员变量，只能访问静态成员变量
    // （3） 本质：静态成员函数中是没有this指针
    // （4） 静态成员函数实际上就是带类域的全局函数
    static void foo();

public:
    // 静态成员变量
    // （1） 要单独的把实现写在类外(.cpp中)
    // （2） 默认会用0对该成员进行初始化
    // （3） 静态成员变量是同一个类的不同对象共用的，所以不占用类的内存大小
    // （4） 本质：带类域的全局变量
    static int m_nStatic; //静态成员变量声明

private:
    int m_nNumber;
};

int CInteger::GetNumber() const
{
    return m_nNumber;
}

void CInteger::foo()
{
    printf("CInteger::foo");

    // m_nNumber = 1;  //报错，静态成员函数不能访问非静态成员变量，会报错
    m_nStatic = 2;  // OK,静态成员函数 可以访问静态成员变量
    // void *p = this; //报错，this指针只能用于非静态成员函数内部
}

int CInteger::m_nStatic; //静态成员变量实现

int main(int argc, char *argv[])
{
    CInteger i1 = 1;
    i1.foo();

    CInteger::foo();  //访问静态成员变量，不依赖对象，本质是带类域的全局函数

    return 0;
}