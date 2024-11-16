/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touahman <touahman@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 08:31:48 by touahman          #+#    #+#             */
/*   Updated: 2024/11/14 08:31:57 by touahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
  Fixed               operator++(int); 
  Fixed&              operator++();
  Fixed               operator--(int); 
  Fixed&              operator--();

  static Fixed&       min(Fixed &point1, Fixed &point2);
  static Fixed&       max(Fixed &point1, Fixed &point2);
  static const Fixed& min(const Fixed &point1, const Fixed &point2);
  static const Fixed& max(const Fixed &point1, const Fixed &point2);
};

std::ostream          &operator<<(std::ostream &out, const Fixed &other);

#endif
