#include <iostream>
#include <string>

using namespace std;

//苹果
class Apple
{
public:
    void getName()
    {
        cout << "我是苹果" << endl;
    }
};

//香蕉
class Banana
{
public:
    void getName()
    {
        cout << "我是香蕉" << endl;
    }
};

//梨子
class Pear
{
public:
    void getName()
    {
        cout << "我是梨子" << endl;
    }
};

//工厂
class Factory
{
public:
    //水果生产器
    Apple *createApple(string kind)
    {
        if (this->kind == "apple")
        {
            return new Apple();
        }
    }
    Banana *createBanana(string kind)
    {
        if (this->kind == "banana")
        {
            return new Banana();
        }
    }
    Pear *createPear(string kind)
    {
        if (this->kind == "pear")
        {
            return new Pear();
        }
    }

private:
    string kind;
};

int main(void){
    Factory *factory = new Factory();
    Apple* apple = factory->createApple("apple");
    apple->getName();

    Pear* pear = factory->createPear("pear");
    pear->getName();

    delete factory;
    delete apple;
    delete pear;

    return 0;
}