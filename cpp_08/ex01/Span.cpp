#include "Span.hpp"

Span::Span() : n(0){
    std::cout<<"Default constructor is called!\n";
}

Span::Span(unsigned int num) : n(num) {
    std::cout<<"Constructor with parameters is called!\n";
}

Span::Span(const Span& original) {
    std::cout<<"Copy constructor is called!\n";
    this->n = original.n;
    this->vec = original.vec;
}

Span& Span::operator=(const Span& original) {
    if (this == &original)
        return (*this);
    this->n = original.n;
    this->vec = original.vec;

    return (*this);
}

void Span::addNumber(int value) {
    if (vec.size() < n)
        vec.push_back(value);
    else
        throw std::out_of_range("AddNumber: The collection is full!\n");
}

int	Span::shortestSpan() {
    std::vector<int> copy(vec);

    std::sort(copy.begin(), copy.end());

    int shortestSpan = copy[1] - copy[0];
    for (size_t i = 2; i < copy.size(); i++)
    {
        if (copy[i] - copy[i-1] < shortestSpan)
            shortestSpan = copy[i] - copy[i-1];
    }
    return (shortestSpan);
}

int Span::longestSpan() {
    if (vec.size() < 2) {
        throw std::length_error("Not enough elements to calculate a span");
    }

    std::vector<int> copy(vec);
    std::sort(copy.begin(), copy.end());

    int longestSpan = copy.back() - copy.front(); //copy.front() is equivalent *vec.begin()    
    return longestSpan;
}

Span::~Span() {
    std::cout<<"Destructor with parameters is called!\n";
}