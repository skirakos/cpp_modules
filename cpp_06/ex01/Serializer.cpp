#include "Serializer.hpp"
#include <cctype>
#include <climits>
#include <limits.h>

Serializer::Serializer() {
    //std::cout<<"Serializer constructor is called!\n";
}
Serializer::Serializer(const Serializer&) {
    //std::cout<<"Serializer copy constructor is called!\n";
}
Serializer& Serializer::operator=(const Serializer& ) {
    // std::cout << "Copy assignment of Serializer operator called\n";
    return *this;
}

uintptr_t Serializer::serialize(Data* ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw) {
    return reinterpret_cast<Data*>(raw);
}


Serializer::~Serializer() {
    std::cout<<"Serializer decstructor is called!\n";
}


// inf     Positive Infinity (1.0 / 0.0)
// -inf    Negative Infinity (-1.0 / 0.0)
// nan     Not a Number (e.g., sqrt(-1))
// inff    Infinity (float type)
// -inff   Negative Infinity (float type)
