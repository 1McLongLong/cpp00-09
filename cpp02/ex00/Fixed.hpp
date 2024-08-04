#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>


class Fixed {
  int nbr;
  static const int bits;

  public:
  Fixed();
  Fixed(const Fixed &copy);
  ~Fixed();
  int getRawBits( void ) const;
  void setRawBits( int const raw );
};


#endif
