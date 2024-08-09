#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
  int nbr;
  static const int bits;

  public:
  Fixed();
  Fixed(const int nb);
  Fixed(const float nb);
  Fixed(const Fixed &copy);
  Fixed &operator=(const Fixed &other);
  ~Fixed();
  int getRawBits( void ) const;
  void setRawBits( int const raw );
  float toFloat( void ) const;
  int toInt( void ) const;
};

std::ostream &operator<<(std::ostream &o, Fixed const &rhs);

#endif
