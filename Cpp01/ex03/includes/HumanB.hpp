#ifndef __HUMANB_HPP__
# define __HUMANB_HPP__

#include "Weapon.hpp"

class HumanB
{
    private:
        std::string _name;
        Weapon*     _weapon;

    public:
        // Constructors & Destructor
        HumanB();
        HumanB(const std::string& name);
        ~HumanB();

        // Setters
        void                setWeapon(Weapon& weapon);

        // Member functions
        void                attack(void);
};

#endif // __HUMANB_HPP__