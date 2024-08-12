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

  int   getRawBits( void ) const;
  void  setRawBits( int const raw );
  int   toInt( void ) const;
  float toFloat( void ) const;

  bool  operator>(Fixed const &other) const;
  bool  operator<(Fixed const &other) const;
  bool  operator>=(Fixed const &other) const;
  bool  operator<=(Fixed const &other) const;
  bool  operator==(Fixed const &other) const;
  bool  operator!=(Fixed const &other) const;
  Fixed operator+(Fixed const &other) const;
  Fixed operator-(Fixed const &other) const;
  Fixed operator*(Fixed const &other) const;
  Fixed operator/(Fixed const &other) const;
  Fixed operator++(int); // prefix
  Fixed& operator++();
  Fixed operator--(int); // prefix
  Fixed& operator--();

  static Fixed& min(Fixed &point1, Fixed &point2);
  static Fixed& max(Fixed &point1, Fixed &point2);
  static const Fixed& min(Fixed const &point1, Fixed const &point2);
  static const Fixed& max(Fixed const &point1, Fixed const &point2);
};

std::ostream &operator<<(std::ostream &o, Fixed const &other);

#endif
