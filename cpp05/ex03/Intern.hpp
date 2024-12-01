#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
public: 
  class Error : public std::exception {
    const char* what() const throw();
  };
  AForm *makeForm(std::string formName, std::string target);
};


#endif
