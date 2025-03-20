#ifndef SCALARCONVERTER
#define SCALARCONVERTER


#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <climits>
#include <limits>

class ScalarConverter {
  ScalarConverter();
  ScalarConverter(const ScalarConverter &copy);
  ScalarConverter &operator=(const ScalarConverter &copy);
  ~ScalarConverter();

public:
  static void convert(const std::string &str);
};






#endif
