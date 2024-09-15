#ifndef __FIXED_HPP__
# define __FIXED_HPP__

#include <iostream> // std::cout, std::endl
#include <cmath>    // std::pow

class Fixed 
{
    private:
        int                 _fixedPointValue;
        static const int    _fractionalBits = 8;

    public:
        Fixed();                                    // Default constructor
        Fixed(const int value);                     // Int constructor
        Fixed(const float value);                   // Float constructor
        Fixed(const Fixed &original);               // Copy constructor
        Fixed &operator=(const Fixed &original);    // Copy assignment operator
        ~Fixed();                                   // Destructor

        // Setters
        void            setRawBits(int const raw);

        // Getters
        int             getRawBits(void) const;
      

        // Member Functions
        float           toFloat(void) const;
        int             toInt(void) const;
        static  void    printMsg(const std::string& msg, const std::string& color);

};

std::ostream &operator<<(std::ostream &out, const Fixed &value);

#endif // __FIXED_HPP__