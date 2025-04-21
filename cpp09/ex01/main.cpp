#include "RPN.hpp"


int main(int argc, char **argv) {
  if (argc != 2) {
    std::cerr << "Error: wrong arguments" << std::endl;
    return 1;
  }
  try {
    RPN rpn;
    rpn.calculate(argv);
  }
  catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
  return 0;
}
