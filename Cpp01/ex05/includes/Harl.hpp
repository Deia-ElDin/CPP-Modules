#ifndef __HARL_HPP__
# define __HARL_HPP__

#include <string>
#include <iostream>

class Harl
{
    private:
        void    debug(void);
        void    info(void);
        void    warning(void);
        void    error(void); 

    public:
        void    complain(std::string level);
};

int getLevelNumber(std::string level);


#endif // __HARL_HPP__