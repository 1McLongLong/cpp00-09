#include "Span.hpp"
#include <ctime>

int main() {
  try {
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
  }
  catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  std::cout << "--------------------------------"<< std::endl;
  try {
    Span sp = Span(10000);
    std::vector<int> numbers;

    std::srand((unsigned int)std::time(0));
    for (int i = 0; i < 10000; i++)
      numbers.push_back(std::rand());

    sp.addNumber(numbers.begin(), numbers.end());
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
  }
  catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  return 0;
}
