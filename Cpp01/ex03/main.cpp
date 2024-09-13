#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
    {
        Weapon club = Weapon("crude spiked club");
        HumanA bob("Bob", club);

        bob.attack();
        club.setType("some other type of club");
        bob.attack();
    }
    {
        Weapon club = Weapon("crude spiked club");
        HumanB jim("Jim");

        jim.setWeapon(club);
        jim.attack();
        club.setType("some other type of club");
        jim.attack();
    }
    return 0;
}

/*
    The reason HumanA uses a reference (Weapon& _weapon) while HumanB uses a pointer (Weapon* _weapon) is based on the following distinctions between the two characters:

    HumanA:

    Weapon reference (Weapon&): The reference to a weapon in HumanA means that HumanA must always have a weapon. A reference cannot be null, so it enforces that HumanA is armed at all times. This is why the weapon is passed in the constructor, and once set, HumanA will always refer to a valid weapon object.
    Why a reference: Since HumanA must always be armed, the reference guarantees that HumanA cannot exist without a weapon. This fits the narrative that HumanA always attacks with a weapon.
    HumanB:

    Weapon pointer (Weapon*): The pointer in HumanB allows for the possibility that HumanB may or may not have a weapon. A pointer can be null, which means HumanB can exist without a weapon initially (as you see with the default constructor where no weapon is provided).
    Why a pointer: Since HumanB may not start with a weapon, the pointer allows flexibility. HumanB can later be assigned a weapon through the setWeapon() function. If HumanB does not have a weapon initially, the pointer can be null, which is valid for the design of this class.

    In summary:

    Weapon& in HumanA ensures that HumanA always has a weapon (since references must be valid objects).
    Weapon in HumanB* provides the flexibility for HumanB to be weaponless initially and be armed later (since pointers can be null).
*/
