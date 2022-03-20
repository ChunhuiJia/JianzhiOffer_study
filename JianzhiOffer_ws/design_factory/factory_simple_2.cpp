#include <iostream>
#include <string>

using namespace std;

class Fruit
{
public:
    virtual void getName() = 0;
};

//苹果
class Apple : public Fruit
{
public:
    virtual void getName()
    {
        cout << "我是苹果" << endl;
    }
};

//香蕉
class Banana : public Fruit
{
public:
    virtual void getName()
    {
        cout << "我是香蕉" << endl;
    }
};

//梨子
class Pear : public Fruit
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
    Fruit *createFruit(string kind)
    {
        if (kind == "apple")
        {
            return new Apple();
        }
        else if (kind == "banana")
        {
            return new Banana();
        }
        else if(kind == "pear"){
            return new Pear;
        }
    }
};

//简单工厂模式
int main(void)
{
    Factory *factory = new Factory();
    Fruit *apple = factory->createFruit("apple");
    apple->getName();
    Fruit *banana = factory->createFruit("banana");
    banana->getName();
    Fruit *pear = factory->createFruit("pear");
    pear->getName();
    delete factory;
    delete apple;
    delete banana;
    delete pear;

    return 0;
}