#include "Fixed.hpp"

const int Fixed::bits = 8;

Fixed::Fixed()
{
  nbr = 0;
  std::cout << "Default constructor called\n";
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

// int Fixed::getRawBits( void ) const
// {
//   std::cout << "getRawBits member function called\n";
//   return (nbr);
// }
//
// void Fixed::setRawBits( int const raw )
// {
//   nbr = raw;
// }


