#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat obj1 = Bureaucrat("Bob", 152);
        obj1.increment();
        // std::cout<<obj1.getGrade()<<std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}