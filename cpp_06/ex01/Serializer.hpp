#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <sstream>
#include <string>
#include "Data.hpp"
#include <cstdint>

class Serializer {
    private:
        Serializer();
        Serializer(std::string newName, int newGradeS, int newGradeE);
        Serializer(const Serializer&);
        Serializer& operator=(const Serializer&);
        ~Serializer();
    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};

std::ostream& operator<<(std::ostream& os, const Serializer& obj);

#endif