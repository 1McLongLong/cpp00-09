#include "ScalarConverter.hpp"


ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &copy) {
  *this = copy;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &copy) {
  (void)copy;
  return *this;
}

ScalarConverter::~ScalarConverter() {}


std::string ScalarConverter::to_string(double value) {
    std::ostringstream oss;
    oss << value;
    return oss.str();
}

void ScalarConverter::convertToInt(const std::string &str) {
  char *endptr;
  long temp = std::strtol(str.c_str(), &endptr, 10);
  if (temp > INT_MAX || temp < INT_MIN) {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
    return;
  }
  int i = static_cast<int>(temp);
  char c = static_cast<char>(i);
  float f = static_cast<float>(i);
  double d = static_cast<double>(i);
  std::cout << "char: " << ((c == i && std::isprint(c)) ? "'" + std::string(1, c) + "'" : "Non displayable") << std::endl;
  std::cout << "int: " << i << std::endl;
  std::cout << "float: " << to_string(f) + ".0f" << std::endl;
  std::cout << "double: " << to_string(d) + ".0" << std::endl;
}

void ScalarConverter::convertToFloatOrDouble(double &value) {
  float fValue = static_cast<float>(value);

  int i = static_cast<int>(value);
  char c = static_cast<char>(i);
  std::cout << "char: ";
  if (value < 0 || value > 127 || !std::isprint(c))
    std::cout << "Non displayable" << std::endl;
  else
    std::cout << "'" << c << "'" << std::endl;

  if (value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min()) {
    std::cout << "int: Impossible\n";
  } else {
    std::cout << "int: " << i << "\n";
  }

  // Float and double printing with proper formatting
  std::cout << "float: " << fValue;
  if (fValue == i) std::cout << ".0";
  std::cout << "f\n";

  std::cout << "double: " << value;
  if (value == i) std::cout << ".0";
  std::cout << "\n";
}

bool ScalarConverter::isPureInteger(const std::string &str) {
  size_t i = (str[0] == '-') ? 1 : 0; // Skip negative sign if present
  while (i < str.length()) {
    if (!std::isdigit(str[i])) return false;
    i++;
  }
  return true;
}

void ScalarConverter::convert(const std::string &str) {
  if (str.length() == 1 && !std::isdigit(str[0]) && std::isprint(str[0])) {
    std::cout << "char: '" << str[0] << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(str[0]) << std::endl;
    std::cout << "float: " << static_cast<float>(str[0]) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(str[0]) << ".0" << std::endl;
    return ;
  }
  if (str == "-inff" || str == "+inff" || str == "nanf") {
    std::string str2 = str;
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: " << str2 << std::endl;
    std::cout << "double: " << str2.erase(str.length() - 1) << std::endl;
    return ;
  } 
  if (str == "-inf" || str == "+inf" || str == "nan") {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: " << str << "f" << std::endl;
    std::cout << "double: " << str << std::endl;
    return ;
  }
  if (isPureInteger(str)) {
    convertToInt(str);
    return ;
  }
  else {
    if (str[0] == '.') {
      std::cout << "INVALID INPUT\n";
      return;
    }
    char *endptr;
    bool isFloat = (str[str.length() - 1] == 'f');
    double value = std::strtod(str.c_str(), &endptr); // Convert to double
    if (isFloat) {
      if (str[str.length() - 2] == '.') {
        std::cout << "INVALID INPUT\n";
        return;
      }
    }
    // Handle invalid input (e.g., "abc", "42abc")
    if (*endptr != '\0' && (!isFloat || *endptr != 'f' || *(endptr + 1) != '\0')) {
      std::cout << "INVALID INPUT\n";
      return;
    }
    convertToFloatOrDouble(value);
  }
}

