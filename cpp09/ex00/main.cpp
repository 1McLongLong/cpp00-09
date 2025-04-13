#include "BitcoinExchange.hpp"


int main (int argc, char *argv[]) {
  if (argc != 2) {
    std::cerr << "Error: wrong number of arguments" << std::endl;
    return 1;
  }
  try {
    BitcoinExchange exchange(argv[1]);
    exchange.processInput();
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
    return 1;
  }
  return 0;
}
