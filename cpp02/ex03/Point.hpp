#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
  const Fixed m_x;
  const Fixed m_y;

public:
  Point();
  Point(const float x, const float y);
  Point(const Point &copy);
  Point &operator=(const Point &copy);
  ~Point();
  Fixed get_x() const;
  Fixed get_y() const;
};



std::ostream &operator<<(std::ostream &o, Point const &other);



#endif
