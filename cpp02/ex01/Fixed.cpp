/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touahman <touahman@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 08:31:59 by touahman          #+#    #+#             */
/*   Updated: 2024/11/14 08:32:00 by touahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::bits = 8;

Fixed::Fixed() : nbr(0) {
  std::cout << "Default constructor called\n";
}

Fixed::Fixed(const int intValue) {
  nbr = intValue << bits;
  std::cout << "Int constructor called\n";
}

Fixed::Fixed(const float floatValue) {
	nbr = roundf(floatValue * (1 << bits));
  std::cout << "Float constructor called\n";
}

Fixed::Fixed(const Fixed &copy) {
  std::cout << "Copy constructor called\n";
  this->nbr = copy.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &other) {
  std::cout << "Copy assignment operator called\n";
  if(this != &other) {
    this->nbr = other.getRawBits();
  }
  return *this;
}

Fixed::~Fixed() {
  std::cout << "Destructor called\n";
}

int Fixed::getRawBits(void) const {
  return nbr;
}

void Fixed::setRawBits(int const raw) {
  nbr = raw;
}

float Fixed::toFloat(void) const {
  return (float)nbr / (1 << bits);
}

int Fixed::toInt(void) const {
  return nbr >> bits;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
  out << fixed.toFloat();
  return out;
}
