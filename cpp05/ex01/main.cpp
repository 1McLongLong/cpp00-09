#include "Bureaucrat.hpp"

int main()
{
  try {
    try {
      Bureaucrat test("test", 200);	
    }
    catch(const std::exception& e) {
      std::cerr << e.what() << '\n';
    }
    Bureaucrat a("a", 150);
    Bureaucrat b("b", 1);

    std::cout << a << std::endl;
    std::cout << b << std::endl;

    a.incGrade();
    b.decGrade();
    std::cout << a << std::endl;
    std::cout << b << std::endl;
  }
  catch(const std::exception& e) {
    std::cerr << e.what() << '\n';
  }
  return (0);
}
