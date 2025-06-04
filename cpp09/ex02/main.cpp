#include "PmergeMe.hpp"

bool is_space(char *str) {
  for (int i = 0; str[i]; i++) {
    if (str[i] == ' ')
      return true;
  }
  return false;
}

int main (int argc, char *argv[]) {
  if (argc == 1) {
    std::cout << "No arguments" << std::endl;
    return 1;
  }
  if (argc == 2) {
    if (is_space(argv[1]) || std::string(argv[1]) == "") {
      std::cout << "Error!!!" << std::endl;
      return 1;
    }
  }
  try {
    PmergeMe merge(argc, argv);
    merge.sort();
  }
  catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
    return 1;
  }
  return 0;
}
