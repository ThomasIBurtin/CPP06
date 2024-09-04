
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate(void)
{
    std::srand(static_cast<unsigned int>(std::time(0)));
    int random_number = std::rand() % 3 + 1;
    Base *base = NULL;
    switch(random_number)
    {
        case 1:
            base = new A();
            return base;

        case 2:
            base = new B();
            return base;

        case 3:
            base = new C();
            return base;

        default:
            return NULL;
    }
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Probleme" << std::endl;
}

void identify(Base& p)
{
    if (dynamic_cast<A*>(&p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(&p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(&p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Probleme" << std::endl;
}

int main()
{
    Base *base = generate();
    identify(base);
    identify(*base);
    delete base;
}