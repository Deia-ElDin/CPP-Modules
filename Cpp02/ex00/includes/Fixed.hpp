#ifndef __FIXED_HPP__
# define __FIXED_HPP__

#include <iostream> // std::cout, std::endl

class Fixed 
{
    private:
        int                 _fixedPointValue;
        static const int    _fractionalBits = 8;

    public:
        Fixed();                                    // Default constructor
        Fixed(const Fixed &original);               // Copy constructor
        Fixed &operator=(const Fixed &original);    // Copy assignment operator
        ~Fixed();                                   // Destructor

        // Setters
        void            setRawBits(int const raw);

        // Getters
        int             getRawBits(void) const;

        // Member Functions
        static  void    printMsg(const std::string& msg, const std::string& color);
};

#endif // __FIXED_HPP__
