#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() {
    Intern newPie;

    AForm* shrubberyForm = newPie.makeForm("shrubbery creation", "Form-A");
    AForm* robotomyForm = newPie.makeForm("robotomy request", "Form-B");
    AForm* pardonForm = newPie.makeForm("presidential pardon", "Form-C");
    newPie.makeForm("unknown form", "Form-D");

    delete shrubberyForm;
    delete robotomyForm;
    delete pardonForm;

    return 0;
}
