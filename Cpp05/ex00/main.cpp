#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat deia("Deia", 2);
        std::cout << deia << std::endl;

        deia.incrementGrade();
        std::cout << deia << std::endl;

        deia.incrementGrade();  
        std::cout << deia << std::endl;
    } catch (std::exception& e) {
        Utils::printErr(e.what());
    }

    try {
        Bureaucrat ahmed("Ahmed", 150);
        std::cout << ahmed << std::endl;

        ahmed.decrementGrade();
    } catch (std::exception& e) {
        Utils::printErr(e.what());
    }

    return 0;
}
