#ifndef __WEAPON_HPP__
# define __WEAPON_HPP__

#include <iostream>
#include <string>

class Weapon
{
    private:
        std::string _type;

    public:
        Weapon();
        Weapon(std::string type);
        ~Weapon();

        // Setters
        void                setType(std::string type);

        // Getters
        std::string const&  getType(void);
};

#endif // __WEAPON_HPP__