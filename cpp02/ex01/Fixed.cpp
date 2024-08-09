#include "Fixed.hpp"

const int Fixed::bits = 8;

Fixed::Fixed()
{
  nbr = 0;
  std::cout << "Default constructor called\n";
}

Fixed::Fixed(const int nb)
{
  nbr = nb << bits;
  std::cout << "Int constructor called\n";
}

Fixed::Fixed(const float nb)
{
	nbr = roundf(nb * (1 << bits));
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

std::ostream &operator<<(std::ostream &o, Fixed const &rhs)
{
  o << rhs.toFloat();
  return o;
}
