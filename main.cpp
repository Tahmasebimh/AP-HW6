#include <iostream>
#include <bits/shared_ptr.h>
#include <array>


class Base
{
public:
    Base(){
        std::cout << "Base Constructor Called\n";
    }
    virtual ~Base(){
        std::cout << "Base Destructor called\n";
    }
};
class Derived1: public Base
{
public:
    Derived1(){
        std::cout << "Derived constructor called\n";
    }
    ~Derived1(){
        std::cout << "Derived destructor called\n";
    }
};
int main() {
//    Base *b = new Derived1();
//    delete b;



    return 0;
}
