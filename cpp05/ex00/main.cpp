#include "Bureaucrat.hpp"


int main() {
  try {
    Bureaucrat	person("Kel", 10);
    std::cout << person << std::endl;
  }
  catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
}
