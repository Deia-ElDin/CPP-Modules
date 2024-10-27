#ifndef __ROBOTOMY_REQUEST_FORM__
# define __ROBOTOMY_REQUEST_FORM__

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    private:
        std::string _target;

    public:
        RobotomyRequestForm(const std::string& target);
        ~RobotomyRequestForm();

        void    execute(Bureaucrat const & executor) const;
};

#endif // __ROBOTOMY_REQUEST_FORM__