#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "Utils.hpp"

int main() {
    try {
        Bureaucrat  deia("Deia", 4);
        Bureaucrat  ahmed("Ahmed", 3);
        Form        form("Day off form", 3, 3);

        std::cout << form << std::endl;

        deia.signForm(form);
        ahmed.signForm(form);

        std::cout << form << std::endl;
        std::cout << deia << std::endl;
        std::cout << ahmed << std::endl;

        deia.incrementGrade();
        std::cout << deia << std::endl;

        deia.signForm(form);
        std::cout << form << std::endl;
    } catch (const std::exception& e) {
        Utils::printErr(e.what());
    }
    return 0;
}
