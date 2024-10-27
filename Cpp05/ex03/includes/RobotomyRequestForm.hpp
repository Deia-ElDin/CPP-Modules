#ifndef __ROBOTOMY_REQUEST_FORM__
# define __ROBOTOMY_REQUEST_FORM__

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    private:
        std::string _target;

    public:
        RobotomyRequestForm();
        RobotomyRequestForm(const std::string& target);
        RobotomyRequestForm(const RobotomyRequestForm& other); 
        RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
        ~RobotomyRequestForm();
        
        void    execute(Bureaucrat const & executor) const;
};

#endif // __ROBOTOMY_REQUEST_FORM__