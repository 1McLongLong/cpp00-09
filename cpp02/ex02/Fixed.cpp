/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touahman <touahman@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 08:31:39 by touahman          #+#    #+#             */
/*   Updated: 2024/11/14 09:44:05 by touahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::bits = 8;

Fixed::Fixed() : nbr (0)
{}

Fixed::Fixed(const int intValue) {
  nbr = intValue << bits;
}

Fixed::Fixed(const float floatValue) {
	nbr = roundf(floatValue * (1 << bits));
}

Fixed::Fixed(const Fixed &copy) {
  this->nbr = copy.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &other) {
  if(this != &other) {
    this->nbr = other.getRawBits();
  }
  return *this;
}

Fixed::~Fixed()
{}

int Fixed::getRawBits( void ) const {
  return nbr;
}

void Fixed::setRawBits( int const raw ) {
  nbr = raw;
}

float Fixed::toFloat( void ) const {
  return (float)this->nbr / (1 << bits);
}

int Fixed::toInt( void ) const {
  return nbr >> bits;
}

std::ostream &operator<<(std::ostream &out, const Fixed &other) {
  out << other.toFloat();
  return out;
}

bool Fixed::operator>(const Fixed &other) const {
  return this->nbr > other.getRawBits();
}

bool Fixed::operator<(const Fixed &other) const {
  return this->nbr < other.getRawBits();
}

bool Fixed::operator>=(const Fixed &other) const {
  return this->nbr >= other.getRawBits();
}

bool Fixed::operator<=(const Fixed &other) const {
  return this->nbr <= other.getRawBits();
}

bool Fixed::operator==(const Fixed &other) const {
  return this->nbr == other.getRawBits();
}

bool Fixed::operator!=(const Fixed &other) const {
  return this->nbr != other.getRawBits();
}

Fixed Fixed::operator+(const Fixed &other) const {
  Fixed res;
  res.setRawBits(this->nbr + other.getRawBits());
  return res;
}

Fixed Fixed::operator-(const Fixed &other) const {
  Fixed res;
  res.setRawBits(this->nbr - other.getRawBits());
  return res;
}

Fixed Fixed::operator*(const Fixed &other) const {
  Fixed res;
  res.setRawBits(this->nbr * other.getRawBits() / (1 << bits));
  return res;
}

Fixed Fixed::operator/(const Fixed &other) const {
  Fixed res;
  res.setRawBits((this->nbr * (1 << bits)) / other.getRawBits());
  return res;
}

Fixed& Fixed::operator++() {
  ++nbr;
  return *this;
}

Fixed& Fixed::operator--() {
  --nbr;
  return *this;
}

Fixed Fixed::operator++(int) {
  Fixed fixed(*this);
  nbr++;
  return fixed;
}

Fixed Fixed::operator--(int) {
  Fixed fixed(*this);
  nbr--;
  return fixed;
}

Fixed& Fixed::min(Fixed &point1, Fixed &point2) {
  if (point1 < point2)
    return point1;
  else 
    return point2;
}

const Fixed& Fixed::min(const Fixed &point1, const Fixed &point2) {
  if (point1 < point2)
    return point1;
  else
    return point2;
}

Fixed& Fixed::max(Fixed &point1, Fixed &point2) {
  if (point1 > point2)
    return point1;
  else 
    return point2;
}

const Fixed& Fixed::max(const Fixed &point1, const Fixed &point2) {
  if (point1 > point2)
    return point1;
  else 
    return point2;
}
