#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm(target, 145, 137), _target(target) {
        Utils::printMsg("Shrubbery Creation Form parameter constructor called", "yellow");
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    Utils::printMsg("Shrubbery Creation Form destructor called", "purple");
}

void    ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
    if (!getIsSigned()) throw FormNotSignedException();

    if (executor.getGrade() > getExecuteGrade()) throw GradeTooLowException();

    std::ofstream file(_target + "_shrubbery");

    if (!file) return (Utils::printErr("Error: Could not create the file."));

    file << "                                                         .    \n"
         << "                                              .         ;     \n"
         << "                 .              .              ;%     ;;      \n"
         << "                   ,           ,                :;%  %;       \n"
         << "                    :         ;                   :;%;'     .,\n"
         << "           ,.        %;     %;            ;        %;'    ,;  \n"
         << "             ;       ;%;  %%;        ,     %;    ;%;    ,%'   \n"
         << "              %;       %;%;      ,  ;       %;  ;%;   ,%;'    \n"
         << "               ;%;      %;        ;%;        % ;%;  ,%;'      \n"
         << "                `%;.     ;%;     %;'         `;%%;.%;'        \n"
         << "                 `:;%.    ;%%. %@;        %; ;@%;%'           \n"
         << "                    `:%;.  :;bd%;          %;@%;'             \n"
         << "                      `@%:.  :;%.         ;@@%;'              \n"
         << "                        `@%.  `;@%.      ;@@%;                \n"
         << "                          `@%%. `@%%    ;@@%;                 \n"
         << "                            ;@%. :@%%  %@@%;                  \n"
         << "                              %@bd%%%bd%%:;                   \n"
         << "                                #@%%%%%:;;                    \n"
         << "                                %@@%%%::;                     \n"
         << "                                %@@@%(o);  . '                \n"
         << "                                %@@@o%;:(.,'                  \n"
         << "                            `.. %@@@o%::;                     \n"
         << "                               `)@@@o%::;                     \n"
         << "                                %@@(o)::;                     \n"
         << "                               .%@@@@%::;                     \n"
         << "                               ;%@@@@%::;.                    \n"
         << "                              ;%@@@@%%:;;;.                   \n"
         << "                          ...;%@@@@@%%:;;;;,..                \n";

    file.close();
}
