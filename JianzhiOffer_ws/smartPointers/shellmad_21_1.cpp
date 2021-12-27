// shared_ptr和weak_ptr(弱指针，是对前面shared_ptr的一种补充)
// shared_ptr是带引用计数的智能指针

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

void foo_construct()
{
    int *p = new int(3);

    std::shared_ptr<int> sptr(p);           //不推荐这样的写法
    std::shared_ptr<int> sptr2(new int(4)); //推荐这样的写法
    std::shared_ptr<int> sptr3 = sptr2;
    std::shared_ptr<int> sptr4 = std::make_shared<int>(5);
    int a = 10;
}

void foo_construct2()
{
    int *p = new int(3);
    {
        std::shared_ptr<int> sptr(p); //由于p已经被释放，所以这个地方会出错
        {
            std::shared_ptr<int> sptr2(p); //离开这个作用域时会释放p
        }
    }
}

// 为什么需要weak_ptr
// 为了避免循环引用问题
// 循环的引用，会出现析构异常
// 使用了weak_ptr弱指针，才会析构正常
class CPerson;
class CSon;

class Cperson
{
public:
    Cperson()
    {
    }

    void Set(std::shared_ptr<CSon> pSon)
    {
        m_pSon = pSon;
    }

    ~Cperson()
    {
    }

    std::shared_ptr<CSon> m_pSon;  //父亲类包含了一个儿子类的智能指针
    // std::weak_ptr<CSon> m_pSon;  //把其中一个使用了weak_ptr弱指针，才会析构正常
};

class CSon
{
public:
    CSon()
    {
    }

    void Set(std::shared_ptr<Cperson> pParent)
    {
        m_pParent = pParent;
    }

    ~CSon()
    {
    }

    std::shared_ptr<Cperson> m_pParent;   // 儿子类包含了一个父亲类的智能指针
};

void testShared()
{
    CSon* pSon = new CSon();
    Cperson* pPer = new Cperson();

    {
        std::shared_ptr<Cperson> shared_Parent(pPer);  //即使出了作用域还没有被释放掉，智能指针失效了
        std::shared_ptr<CSon> shared_Son(pSon);

        shared_Parent->Set(shared_Son);
        shared_Son->Set(shared_Parent);

        printf("pSon : use_count = %d\r\n", shared_Son.use_count()); //2   //.use_count()是引用的次数
        printf("pParent : use_count = %d\r\n", shared_Parent.use_count());  //2 
    }
}

int main(int argc, char *argv[])
{
    // foo_construct();
    // foo_construct2();
    testShared();  //两个类互相包含另外一个类的智能指针，就会出现互相引用的状态（循环引用）

    return 0;
}