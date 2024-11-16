/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touahman <touahman@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 08:31:32 by touahman          #+#    #+#             */
/*   Updated: 2024/11/14 08:31:34 by touahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>


class Fixed {
  int               nbr;
  static const int  bits;

public:
  Fixed();
  Fixed(const Fixed &copy);
  Fixed &operator=(const Fixed &other);
  ~Fixed();

  int   getRawBits(void) const;
  void  setRawBits(int const raw);
};


#endif
