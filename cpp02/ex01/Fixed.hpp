/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touahman <touahman@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 08:32:01 by touahman          #+#    #+#             */
/*   Updated: 2024/11/14 08:32:06 by touahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
  int nbr;
  static const int bits;

  public:
  Fixed();
  Fixed(const int intValue);
  Fixed(const float floatValue);
  Fixed(const Fixed &copy);
  Fixed &operator=(const Fixed &other);
  ~Fixed();
  int         getRawBits(void) const;
  void        setRawBits(int const raw);
  float       toFloat(void) const;
  int         toInt(void) const;
};

std::ostream  &operator<<(std::ostream &out, const Fixed &rhs);

#endif
