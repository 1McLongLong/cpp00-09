#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
  int               nbr;
  static const int  bits;

public:
  Fixed();
  Fixed(const int nb);
  Fixed(const float nb);
  Fixed(const Fixed &copy);
  Fixed &operator=(const Fixed &other);
  ~Fixed();

  int                 getRawBits(void) const;
  void                setRawBits(int const raw);
  int                 toInt(void) const;
  float               toFloat(void) const;

  bool                operator>(const Fixed &other) const;
  bool                operator<(const Fixed &other) const;
  bool                operator>=(const Fixed &other) const;
  bool                operator<=(const Fixed &other) const;
  bool                operator==(const Fixed &other) const;
  bool                operator!=(const Fixed &other) const;
  Fixed               operator+(const Fixed &other) const;
  Fixed               operator-(const Fixed &other) const;
  Fixed               operator*(const Fixed &other) const;
  Fixed               operator/(const Fixed &other) const;
  Fixed               operator++(int); // postfix
  Fixed&              operator++();
  Fixed               operator--(int); // postfix
  Fixed&              operator--();

  static Fixed&       min(Fixed &point1, Fixed &point2);
  static Fixed&       max(Fixed &point1, Fixed &point2);
  static Fixed&       min(const Fixed &point1, const Fixed &point2);
  static Fixed&       max(const Fixed &point1, const Fixed &point2);
};

std::ostream          &operator<<(std::ostream &out, const Fixed &other);

#endif
