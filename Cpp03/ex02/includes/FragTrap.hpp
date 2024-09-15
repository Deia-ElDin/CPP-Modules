#ifndef __FragTrap_HPP__
# define __FragTrap_HPP__

# include "ClapTrap.hpp"

class   FragTrap : public ClapTrap
{
    public:
        FragTrap();                                 // Default constructor
        FragTrap(std::string name);                 // Name constructor
        FragTrap(const FragTrap& other);            // Copy constructor
        FragTrap& operator=(const FragTrap& other); // Copy assignment operator
        ~FragTrap();                                // Destructor

        void    attack(std::string const& target);
        void    takeDamage(unsigned int amount);
        void    beRepaired(unsigned int amount);
        void    highFivesGuys();
};


#endif // __FragTrap_HPP__