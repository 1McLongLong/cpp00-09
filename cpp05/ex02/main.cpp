#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main() {
	try {
		Bureaucrat b("test", 1);
		ShrubberyCreationForm s("sh-home");
		s.execute(b);
	}
  catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << '\n';
	try {
		Bureaucrat b("test", 10);
		RobotomyRequestForm rb("robot");
		rb.execute(b);
	} 
  catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << '\n';
	try {
		Bureaucrat b("test", 1);
		PresidentialPardonForm pp("Presidential");
		pp.execute(b);
	} 
  catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << '\n';
	try {
		Bureaucrat b("test", 1);
		RobotomyRequestForm rb("robot");
		b.executeForm(rb);

	} 
  catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}
