#include "Intern.hpp"


Intern::Intern()
{}

Intern::Intern(const Intern &copy) {
  *this = copy;
}

Intern &Intern::operator=(const Intern &copy) {
  (void)copy;
  return *this;
}

Intern::~Intern()
{}

const char* Intern::Error::what() const throw() {
  return "Error, the form name passed doesn’t exist!!!";
}

AForm* Intern::createShrubbery(std::string& target) {
  return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomy(std::string& target) {
  return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidential(std::string& target) {
  return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(std::string formName, std::string target) {
  std::string types[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
  AForm* (Intern::*creators[3])(std::string&) = {&Intern::createPresidential, &Intern::createRobotomy, &Intern::createShrubbery};

  for (int i = 0; i < 3; ++i) {
    if (types[i] == formName) {
      std::cout << "Intern creates " << formName << std::endl;
      return (this->*creators[i])(target);
    }
  }
  throw Intern::Error();
}

