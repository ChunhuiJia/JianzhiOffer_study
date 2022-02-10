

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

public:
    // 静态成员变量
    // （1） 要单独的把实现写在类外(.cpp中)
    // （2） 默认会用0对该成员进行初始化
    // （3） 静态成员变量是同一个类的不同对象共用的，所以不占用类的内存大小
    // （4） 本质：带类域的全局变量
    static int m_nStatic;  //静态成员变量声明

private:
    int m_nNumber;
};

int CInteger::GetNumber() const
{
    return m_nNumber;
}

int CInteger::m_nStatic;  //静态成员变量实现

int main(int argc, char *argv[])
{
    CInteger::m_nStatic = 100;  //可以直接访问这个全局变量
    CInteger i1 = 1;
    CInteger i2 = 1;
    int n_size = sizeof(i1);  //4，m_nStatic是全局变量，不占用CInteger的内存空间

    int* pStatic1 = &i1.m_nStatic;
    i1.m_nStatic = 10;
    int* pStatic2 = &i2.m_nStatic;  //i1和i2的m_nStatic成员变量的地址是一样的，所以结果都是10

    i1.m_nStatic = 123;  //会报错，是link阶段报错,因为只有声明没有实现的时候会报这个错
    return 0;
}