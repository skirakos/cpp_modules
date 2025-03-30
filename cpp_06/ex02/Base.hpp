#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <string>

class Base {
    public:
        virtual ~Base();
        virtual void show();
};

class	A : public Base {
    void show();
};
class	B : public Base {
    void show();
};
class	C : public Base {
    void show();
};

Base * generate(void);
void identify(Base* p);
void identify(Base& p);

#endif