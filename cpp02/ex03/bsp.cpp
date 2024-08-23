#include "Fixed.hpp"
#include "Point.hpp"



bool	bsp(const Point a, const Point b, const Point c, const Point point);


float calculateArea(const Point &p1, const Point &p2, const Point &p3) {
  return std::abs(p1.get_x().toFloat() * (p2.get_y().toFloat() - p3.get_y().toFloat()) +
      p2.get_x().toFloat() * (p3.get_y().toFloat() - p1.get_y().toFloat()) +
      p3.get_x().toFloat() * (p1.get_y().toFloat() - p2.get_y().toFloat())) / 2.0f;
}

bool bsp(const Point a, const Point b, const Point c, const Point point) {
  // Calculate the area of the main triangle ABC
  float areaABC = calculateArea(a, b, c);

  // Calculate the area of the triangle PAB, PBC, and PCA
  float areaPAB = calculateArea(point, a, b);
  float areaPBC = calculateArea(point, b, c);
  float areaPCA = calculateArea(point, c, a);

  // Check if the sum of the areas of PAB, PBC, and PCA equals the area of ABC
  if (areaABC == (areaPAB + areaPBC + areaPCA)) {
    return true;
  }

  return false;
}

