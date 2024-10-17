#include "Bureaucrat.hpp"


int main() {
  try {
    Bureaucrat	person("Kel", 160);
    std::cout << person << std::endl;
  }
  catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
}
