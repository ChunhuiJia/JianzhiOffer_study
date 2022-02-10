#include <iostream>

//单例--只有一个实例
class Singleton
{
public:
    ~Singleton()
    {
        printf("~Singleton() destruct");
    }

    // 创建对象的唯一的用户接口
    // static Singleton *CreateObject() //static静态成员函数，可以不依赖对象使用该函数
    // {
    //     if (m_pObject == nullptr)
    //     {
    //         m_pObject = new Singleton();
    //     }
    //     return m_pObject;
    // }

    static Singleton &CreateObject() //static静态成员函数，可以不依赖对象使用该函数
    {
        static Singleton obj; //程序不关闭，static类型的对象不会被释放
        return obj;
    }

private:
    Singleton()
    {
        printf("Singleton() construct");
    }

    Singleton(Singleton &obj) //把拷贝构造函数写到私有里，可以限制Singleton pObj2=Singleton::CreateObject();的语法使用
    {
        printf("Singleton() construct");
    }
    //或
    // Singleton(Singleton &obj)=delete;  //或禁用拷贝构造函数
    Singleton *operator=(Singleton &obj) = delete;  //把=号运算符重载
    // static Singleton *m_pObject;
};

// Singleton *Singleton::m_pObject = nullptr;

int main(int argc, char *argv[])
{
    Singleton &pObj1 = Singleton::CreateObject();
    Singleton &pObj2 = Singleton::CreateObject();
    // Singleton pObj3 = Singleton::CreateObject();
    return 0;
}