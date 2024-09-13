#ifndef __HUMANA_HPP__
# define __HUMANA_HPP__

#include "Weapon.hpp"

class HumanA
{
    private:
        std::string _name;
        Weapon&     _weapon;

    public:
        // Constructor & Destructor
        HumanA(const std::string& name, Weapon& weapon);
        ~HumanA();

        // Member functions
        void    attack(void);
};

#endif // __HUMANA_HPP__

/*
    why passing the reference of the string and the weapon?
        1. Avoiding Object Copying:
            If you use a regular Weapon (i.e., not a reference or pointer), every time you create a HumanA object, a copy of the Weapon object would be created. This could lead to performance overhead if the Weapon class contains large data or complex logic. A reference allows HumanA to directly use the Weapon object passed to it without copying.
        2. Maintaining Consistency:
            When you pass a reference, HumanA operates directly on the original Weapon object. Any changes to the Weapon's state (such as modifying its type via setType()) will reflect on all objects that hold a reference to that Weapon. This ensures that changes made to the weapon's type are visible to HumanA without the need for synchronization.
        3. Logical Ownership:
            A reference signifies that HumanA does not "own" the Weapon object, but rather just uses it. This means the Weapon is managed somewhere else (in your case, likely passed in by another class or function). This matches the semantic meaning: HumanA simply "uses" the weapon but doesn’t manage its lifetime.

    example:
        Weapon sword("Sword");
        HumanA warrior1("Warrior 1", sword);
        HumanA warrior2("Warrior 2", sword);

        sword.setType("Great Sword");

        warrior1.attack();  // Output: Warrior 1 attacks with their Great Sword
        warrior2.attack();  // Output: Warrior 2 attacks with their Great Sword

    Summary:
        -   Using a reference ensures no copying and direct access to the original Weapon object.
        -   It maintains consistency across different objects that reference the same Weapon.
        -   It signals that HumanA does not "own" the Weapon but uses an external object that may be shared or managed by something else.

    This design is efficient and avoids unnecessary duplication of objects in memory. 
    It also ensures that changes to the Weapon object are visible to all objects that reference it.
*/
