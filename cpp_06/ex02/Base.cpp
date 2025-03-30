#include "Base.hpp"

void Base::show() {
    std::cout<<"base\n";
}
void A::show() {
    std::cout<<"A\n";
}
void B::show() {
    std::cout<<"B\n";
}
void C::show() {
    std::cout<<"C\n";
}

Base* generate(void) {
    std::srand(std::time(0));

    int rand = std::rand() % 3;
	if (rand == 0)
    {
		return (new A);
    }
	else if (rand == 1)
    {
		return (new B);
    }
	else{
        return (new C);
    }
		
}
void identify(Base& p) {
    try
    {
        Base& a = dynamic_cast<A&>(p);
        (void)a;
        std::cout<<"A is generated\n";
    }
    catch(const std::exception& e)
    {
        try
        {
            Base& b = dynamic_cast<B&>(p);
            (void)b;
            std::cout<<"B is generated\n";
        }
        catch(const std::exception& e)
        {
            try
            {
                Base& c = dynamic_cast<C&>(p);
                (void)c;
                std::cout<<"C is generated\n";
            }
            catch(const std::exception& e)
            {
                std::cerr << "Unknown object" << e.what() << '\n';
            }
        }
    }
    
}
void identify(Base* p) {
    if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown obj" << std::endl;
     ///we use dynamic cast, because we get the class type randomly, and it isn't known during the compile time
}
Base::~Base() {
    std::cout<<"Base decstructor is called!\n";
}