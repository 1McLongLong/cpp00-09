#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
  try {
    Bureaucrat bob("Bob", 1); // Highest rank
    Bureaucrat tom("Tom", 45); // Medium rank
    Bureaucrat alice("Alice", 140); // Low rank

    // Shrubbery
    ShrubberyCreationForm shrub("Home");
    std::cout << shrub << std::endl;
    bob.signForm(shrub);
    bob.executeForm(shrub);

    std::cout << "------------------------------" << std::endl;

    // Robotomy
    RobotomyRequestForm robo("Bender");
    std::cout << robo << std::endl;
    tom.signForm(robo); // Grade 45 is good enough for signing (requires 72)
    tom.executeForm(robo); // Should be allowed (requires 45)

    std::cout << "------------------------------" << std::endl;

    // Presidential Pardon
    PresidentialPardonForm pardon("Zoidberg");
    std::cout << pardon << std::endl;
    bob.signForm(pardon);
    bob.executeForm(pardon);

    std::cout << "------------------------------" << std::endl;

    // FAIL: Alice too low for signing Shrubbery
    ShrubberyCreationForm shrubFail("bad_shrub");
    std::cout << shrubFail << std::endl;
    alice.signForm(shrubFail);  
    alice.executeForm(shrubFail); // Should not execute

    std::cout << "------------------------------" << std::endl;

    // FAIL: Trying to execute without signing
    RobotomyRequestForm notSigned("TestSubject");
    tom.executeForm(notSigned); // Should throw because not signed

  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
  }

  return 0;
}

