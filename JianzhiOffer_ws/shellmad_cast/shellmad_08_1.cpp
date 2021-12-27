//dynamic_cast （有动态检查指针类型的转换）
// 用于具有虚函数的基类与派生类之间的 **指针或引用** 的转换

//使用dynamic_cast的前提：必须要有虚函数
//具有多态类类型的向下转换时必须使用，其余情况可以不用

#include <iostream>
#include <cstring>

class CFather
{
public:
    CFather()
    {
        m_nTest = 3;
    }

    virtual void foo()
    {
        std::cout << "CFather()::void foo()" << std::endl;
    }

    int m_nTest;
};

class CSon : public CFather
{
public:
    virtual void foo()
    {
        std::cout << "CSon::void foo()" << std::endl;
    }
    int m_nSon;
};

void test1()
{
    CFather f;
    CSon s;

    CFather *pFather = &f;
    CSon *pSon = &s;

    //向下转换，父类转子类指针,不安全
    // pSon = static_cast<CSon *>(pFather); //即使经过转换，pSon还是父类的指针，
    // pSon->m_nSon = 123;                  //实际上没有m_nSon这个成员变量，访问m_nSon实际上是越界访问了，会有问题

    //有一种语法能检测出这种转换是不安全,dynamic_cast，在运行时刻检测转换是否安全
    //dynamic_cast能够在运行的时刻，检测出被转换的指针的类型（依赖RTTI）
    pSon = dynamic_cast<CSon *>(pFather); //若检测到不能正确转换指针类型，则返回空指针nullptr
    if (pSon != nullptr)
    {
        pSon->m_nSon = 123; //不能运行进来
    }

    CFather *pFather1 = &f;
    CSon *pSon1 = &s;
    //向上转换，子类转父类指针，安全
    pFather1 = static_cast<CFather *>(pSon1); //在这里pFather1的地址和pSon1的地址一样，pFather1本质上还是和pSon1的类型一样，也是子类指针
    // pFather1 = static_cast<CFather *>(pSon1); //可以使用，但不推荐使用，因为子类指针转父类指针绝对安全，用dynamic_cast消耗资源
    //dynamic_cast 有额外的开销，一般而言只有在向下转换时才必须使用
    pSon1 = dynamic_cast<CSon *>(pFather1); //这里pFather1是子类指针，所以转换成子类指针没有问题
    if (pSon1 != nullptr)
    {
        pSon1->m_nSon = 456; //能运行进来
    }
}

int main(int argc, char *argv[])
{
    test1();
}