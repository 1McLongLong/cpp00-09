#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
  try {
    Bureaucrat bob("Bob", 1); // Highest
    Bureaucrat tom("Tom", 45); // Medium
    Bureaucrat alice("Alice", 140); // Low

    ShrubberyCreationForm shrub("Home");
    std::cout << shrub << std::endl;
    bob.signForm(shrub);
    bob.executeForm(shrub);

    std::cout << "------------------------------" << std::endl;

    RobotomyRequestForm robo("Bender");
    std::cout << robo << std::endl;
    tom.signForm(robo);
    tom.executeForm(robo);

    std::cout << "------------------------------" << std::endl;

    PresidentialPardonForm pardon("Zoidberg");
    std::cout << pardon << std::endl;
    bob.signForm(pardon);
    bob.executeForm(pardon);

    std::cout << "------------------------------" << std::endl;

    ShrubberyCreationForm shrubFail("bad_shrub");
    std::cout << shrubFail << std::endl;
    alice.signForm(shrubFail);  
    alice.executeForm(shrubFail);

    std::cout << "------------------------------" << std::endl;

    RobotomyRequestForm notSigned("TestSubject");
    tom.executeForm(notSigned);

  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
  }

  return 0;
}

