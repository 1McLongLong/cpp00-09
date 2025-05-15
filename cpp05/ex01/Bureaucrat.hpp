#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

#include "Form.hpp"

class Bureaucrat {
  const std::string name;
  int               grade;

public:
  Bureaucrat();
  Bureaucrat(std::string name, int grade);
  Bureaucrat(const Bureaucrat &copy);
  Bureaucrat &operator=(const Bureaucrat &copy);
  ~Bureaucrat();
  class GradeTooHighException : public std::exception {
    const char* what() const throw();
  };
  class GradeTooLowException : public std::exception {
    const char* what() const throw();
  };
  std::string   getName() const;
  int           getGrade() const;
  void          incGrade();
  void          decGrade();
  void          signForm(Form &form);
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &obj);

#endif
