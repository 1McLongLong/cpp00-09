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
  static std::string  to_string(double value);
  static void         convertToInt(const std::string &str);
  static bool         isPureInteger(const std::string &str);
  static void         convertToFloatOrDouble(double &value);

public:
  ~ScalarConverter();
  ScalarConverter(const ScalarConverter &copy);
  ScalarConverter &operator=(const ScalarConverter &copy);

  static void         convert(const std::string &str);
};






#endif
