#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

class Bureaucrat {
  const std::string name;
  int               grade;
public:
  Bureaucrat(std::string name, int grade);
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

};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &obj);

#endif
