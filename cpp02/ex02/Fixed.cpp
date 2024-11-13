#include "Fixed.hpp"

const int Fixed::bits = 8;

Fixed::Fixed()
{
  nbr = 0;
  std::cout << "Default constructor called\n";
}

Fixed::Fixed(const int int_value)
{
  nbr = int_value * (1 << bits);
  std::cout << "Int constructor called\n";
}

Fixed::Fixed(const float float_value)
{
  int scale = 1 << bits;
	nbr = roundf(float_value * scale);
  std::cout << "Float constructor called\n";
}

Fixed::Fixed(const Fixed &copy)
{
  std::cout << "Copy constructor called\n";
  *this = copy;
}

Fixed &Fixed::operator=(const Fixed &other)
{
  std::cout << "Copy assignment operator called\n";
  if(this != &other)
  {
    this->nbr = other.getRawBits();
  }
  return *this;
}

Fixed::~Fixed()
{
  std::cout << "Destructor called\n";
}

int Fixed::getRawBits( void ) const
{
  return (nbr);
}

void Fixed::setRawBits( int const raw )
{
  nbr = raw;
}

float Fixed::toFloat( void ) const
{
  return (float)this->nbr / (1 << bits);
}

int Fixed::toInt( void ) const
{
  return nbr >> bits;
}

std::ostream &operator<<(std::ostream &out, const Fixed &other)
{
  out << other.toFloat();
  return out;
}

bool Fixed::operator>(const Fixed &other) const
{
  return this->nbr > other.getRawBits();
}

bool Fixed::operator<(const Fixed &other) const
{
  return this->nbr < other.getRawBits();
}

bool Fixed::operator>=(const Fixed &other) const
{
  return this->nbr >= other.getRawBits();
}

bool Fixed::operator<=(const Fixed &other) const
{
  return this->nbr <= other.getRawBits();
}

bool Fixed::operator==(const Fixed &other) const
{
  return this->nbr == other.getRawBits();
}

bool Fixed::operator!=(const Fixed &other) const
{
  return this->nbr != other.getRawBits();
}

//We cannot return by reference a local variable created inside the function, as it would be destroyed when the function exits
Fixed Fixed::operator+(const Fixed &other) const
{
  Fixed res;
  res.setRawBits(this->nbr + other.getRawBits());
  return res;
}

Fixed Fixed::operator-(const Fixed &other) const
{
  Fixed res;
  res.setRawBits(this->nbr - other.getRawBits());
  return res;
}

Fixed Fixed::operator*(const Fixed &other) const
{
  Fixed res;
  res.setRawBits(this->nbr * other.getRawBits() / (1 << bits));
  return res;
}

Fixed Fixed::operator/(const Fixed &other) const
{
  Fixed res;
  res.setRawBits((this->nbr * (1 << bits)) / other.getRawBits());
  return res;
}

Fixed& Fixed::operator++()
{
  ++nbr;
  return *this;
}

Fixed& Fixed::operator--()
{
  --nbr;
  return *this;
}
// dummy argument
Fixed Fixed::operator++(int)
{
  Fixed fixed(*this);
  nbr++;
  return fixed;
}

Fixed Fixed::operator--(int)
{
  Fixed fixed(*this);
  nbr--;
  return fixed;
}

Fixed& Fixed::min(Fixed &point1, Fixed &point2)
{
  if (point1 < point2)
    return point1;
  else 
    return point2;
}

Fixed& Fixed::min(const Fixed &point1, const Fixed &point2)
{
  if (point1 < point2)
    return ((Fixed& )point1);
  else 
    return ((Fixed& )point2);
}

Fixed& Fixed::max(Fixed &point1, Fixed &point2)
{
  if (point1 > point2)
    return point1;
  else 
    return point2;
}

Fixed& Fixed::max(const Fixed &point1, const Fixed &point2)
{
  if (point1 > point2)
    return ((Fixed& )point1);
  else 
    return ((Fixed& )point2);
}



