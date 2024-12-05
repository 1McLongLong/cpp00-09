#include "Form.hpp"
#include "Bureaucrat.hpp"

int	main()
{
	try {
		Bureaucrat b1("test", 1);
		Form f1("Birth certificate", 10, 15);
		std::cout << b1 << std::endl;
		std::cout << f1 << std::endl;
		b1.signForm(f1);
	} 
  catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << '\n' << std::endl;
	
  try {
		Bureaucrat b1("test2", 140);
		Form f1("Certificate", 10, 10);
		std::cout << b1 << std::endl;
		std::cout << f1 << std::endl;
		b1.signForm(f1);
	} 
  catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}
