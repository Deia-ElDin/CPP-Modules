#ifndef __PRESIDENTIAL_PARDON_FORM__
# define __PRESIDENTIAL_PARDON_FORM__

#include "AForm.hpp"
#include <string>

class PresidentialPardonForm : public AForm 
{
    private:
        std::string _target;

    public:
        PresidentialPardonForm();
        PresidentialPardonForm(const std::string& target);
        PresidentialPardonForm(const PresidentialPardonForm& other);
        PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
        ~PresidentialPardonForm();

        void    execute(Bureaucrat const & bureaucrat) const;
};

#endif