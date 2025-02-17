#ifndef SCALARCONVERTER
#define SCALARCONVERTER


#include <iostream>


class ScalarConverter {
  ScalarConverter();
  ScalarConverter(const ScalarConverter &copy);
  ScalarConverter &operator=(const ScalarConverter &copy);
  ~ScalarConverter();
  static bool isChar(const std::string& str);
  static bool isInt(const std::string& str);
  static bool isFloat(const std::string& str);
  static bool isDouble(const std::string& str);

  static void convertToChar(double value);
  static void convertToInt(double value);
  static void convertToFloat(double value);
  static void convertToDouble(double value);

public:
  static void converter(const std::string &str);
};






#endif
