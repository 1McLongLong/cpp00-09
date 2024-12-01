#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
  AForm* createPresidential(std::string& target);
  AForm* createRobotomy(std::string& target);
  AForm* createShrubbery(std::string& target);
public:
  Intern();
  // Intern(const Intern &copy);
  // Intern &operator=(const Intern &copy);
  ~Intern();
  class Error : public std::exception {
    const char* what() const throw();
  };
  AForm *makeForm(std::string formName, std::string target);
};


#endif
