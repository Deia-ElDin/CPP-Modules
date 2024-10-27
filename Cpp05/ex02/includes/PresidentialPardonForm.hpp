#ifndef __PRESIDENTIAL_PARDON_FORM__
# define __PRESIDENTIAL_PARDON_FORM__

#include "AForm.hpp"

class PresidentialPardonForm : public AForm 
{
    private:
        std::string _target;

    public:
        PresidentialPardonForm(const std::string& target);
        ~PresidentialPardonForm();

        void    execute(Bureaucrat const & bureaucrat) const;
};

#endif