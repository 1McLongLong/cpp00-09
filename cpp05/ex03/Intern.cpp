#include "Intern.hpp"


Intern::Intern()
{}

Intern::~Intern()
{}

const char* Intern::Error::what() const throw() {
  return "error";
}

AForm* createShrubbery(std::string& target) {
  return new ShrubberyCreationForm(target);
}

AForm* createRobotomy(std::string& target) {
  return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidential(std::string& target) {
  return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(std::string formName, std::string target) {
  std::string types[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
  AForm* (Intern::*comments[3])(std::string&) = {&Intern::createPresidential, &Intern::createRobotomy, &Intern::createShrubbery};

  for (int i = 0; i < 3; ++i) {
    if (types[i] == formName) {
      std::cout << "Intern creates " << formName << std::endl;
      return (this->*comments[i])(target);
    }
  }
  throw Intern::Error();
  return NULL;
}

