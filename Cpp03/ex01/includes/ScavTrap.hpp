#ifndef __ScavTrap_HPP__
# define __ScavTrap_HPP__

# include "ClapTrap.hpp"

class   ScavTrap : public ClapTrap
{
    public:
        ScavTrap();                                 // Default constructor
        ScavTrap(std::string name);                 // Name constructor
        ScavTrap(const ScavTrap& other);            // Copy constructor
        ScavTrap& operator=(const ScavTrap& other); // Copy assignment operator
        ~ScavTrap();                                // Destructor

        void    attack(std::string const& target);
        void    takeDamage(unsigned int amount);
        void    beRepaired(unsigned int amount);
        void    guardGate();
};


#endif // __ScavTrap_HPP__