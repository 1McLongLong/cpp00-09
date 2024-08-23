#include "Point.hpp"


Point::Point(): m_x(0), m_y(0) {
  // std::cout << "Default constructor called\n";
}

Point::Point(const float x, const float y): m_x(x), m_y(y) {
  // std::cout << "Param constructor called\n";
}

Point::Point(const Point &copy): m_x(copy.m_x), m_y(copy.m_y) {
  *this = copy;
}

Point &Point::operator=(const Point &copy) {
  // std::cout << "Copy assignment operator called\n";
  (void)copy;
  return *this;
}

Point::~Point() {
  // std::cout << "Destructor called\n";
}


Fixed Point::get_x() const {
  return this->m_x;
}

Fixed Point::get_y() const {
  return this->m_y;
}


std::ostream &operator<<(std::ostream &o, Point const &p)
{
  o << "(" << p.get_x().toFloat() << ", " << p.get_y().toFloat() << ")";
  return o;
}
