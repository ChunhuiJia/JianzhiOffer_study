#include <iostream>
#include <memory>

class Mars
{
    public:
    ~Mars()
    {
        std::cout << this << "~Mars" << std::endl;
    }
    void prin()
    {
        std::cout << this << ",I am Mars" << std::endl;
    }
};

int main()
{
    {
        Mars* mars = new Mars;
        std::unique_ptr<Mars> pMars(mars);
        std::cout << "pMars->prin:        ";
        pMars->prin();
        std::cout << "pMars.get()->prin:   ";
        pMars.get()->prin();
        std::cout << "(*pMars).prin:     ";
        (*pMars).prin();

        std::cout << "pMars:" << pMars.get() << std::endl;
        pMars.reset(new Mars);
        std::cout << "pMars.reset.prin:     ";
        pMars->prin();

        std::unique_ptr<Mars> pMars2;
        pMars2 = std::move(pMars);
        std::cout << "pMars2.move.prin:       ";
        std::cout << "pMars2:" << pMars2.get() << std::endl;
        pMars2->prin();
    }

    return 0;
}