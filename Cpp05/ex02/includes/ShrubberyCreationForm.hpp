#ifndef __SHRUBBERY_CREATION_FORM__
# define __SHRUBBERY_CREATION_FORM__

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm 
{
    private:
        std::string _target;
 
    public:
        ShrubberyCreationForm(const std::string& target);
        ~ShrubberyCreationForm();
        
        void    execute(Bureaucrat const & executor) const;
};

#endif  // __SHRUBBERY_CREATION_FORM__