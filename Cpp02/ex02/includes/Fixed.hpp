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

        // Comparison operators
        bool operator>(const Fixed &original) const;
        bool operator<(const Fixed &original) const;
        bool operator>=(const Fixed &original) const;
        bool operator<=(const Fixed &original) const;
        bool operator==(const Fixed &original) const;
        bool operator!=(const Fixed &original) const;

        // Arithmetic operators
        Fixed operator+(const Fixed &original) const;
        Fixed operator-(const Fixed &original) const;
        Fixed operator*(const Fixed &original) const;
        Fixed operator/(const Fixed &original) const;

        // Increment/Decrement operators
        Fixed &operator++(); 
        Fixed operator++(int);  
        Fixed &operator--();   
        Fixed operator--(int);

        // Setters
        void                setRawBits(int const raw);

        // Getters
        int                 getRawBits(void) const;

        // Member Functions
        float               toFloat(void) const;
        int                 toInt(void) const;
        static  void        printMsg(const std::string& msg, const std::string& color);

        // Min/Max functions
        static Fixed        &min(Fixed &a, Fixed &b);
        static const Fixed  &min(const Fixed &a, const Fixed &b);
        static Fixed        &max(Fixed &a, Fixed &b);
        static const Fixed  &max(const Fixed &a, const Fixed &b);

};

std::ostream &operator<<(std::ostream &out, const Fixed &value);

#endif // __FIXED_HPP__