#ifndef __ClapTrap_HPP__
# define __ClapTrap_HPP__

# include <iostream>

class   ClapTrap
{
    protected:
        std::string _name;
        int         _hitPoints;
        int         _energyPoints;
        int         _attackDamage;

    public:
        ClapTrap();                                 // Default constructor
        ClapTrap(std::string name);                 // Name constructor
        ClapTrap(const ClapTrap& other);            // Copy constructor
        ClapTrap& operator=(const ClapTrap& other); // Copy assignment operator
        ~ClapTrap();                                // Destructor

        void    attack(std::string const& target);
        void    takeDamage(unsigned int amount);
        void    beRepaired(unsigned int amount);

        std::string getName() const;
        int         getHitPoints() const;
        int         getEnergyPoints() const;
        int         getAttackDamage() const;

        void        setName(std::string& name);
        void        setHitPoints(int hitPoints);
        void        setEnergyPoints(int energyPoints);
        void        setAttackDamage(int attackDamage);
};


#endif // __ClapTrap_HPP__