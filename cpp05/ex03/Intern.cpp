#include "Intern.hpp"

const char* Intern::Error::what() const throw() {
  return "error";
}

AForm *Intern::makeForm(std::string formName, std::string target) {
  std::string types[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
  // AForm* (*formCreators[3])(const std::string) = {  return new ShrubberyCreationForm(t); , 
  //   return new RobotomyRequestForm(t); ,
  //    return new PresidentialPardonForm(t); 
  // };

  for (int i = 0; i < 3; ++i) {
    if (types[i] == formName) {
      std::cout << "Intern creates " << formName << std::endl;
      // return formCreators[i](target);
    }
  }
  throw Intern::Error();
  return (NULL);
}

