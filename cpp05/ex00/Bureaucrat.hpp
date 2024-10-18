#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>


class Bureaucrat {
  const std::string name;
  int               grade;

public:
  Bureaucrat(std::string name, int grade);
  std::string getName() const;
  int         getGrade() const;
  void        incGrade();
  void        decGrade();

  class GradeTooHighException : public std::exception {
    public:
      const char *what() const throw();
  };
   class GradeTooLowException : public std::exception {
    public:
      const char *what() const throw();
  };
};

std::ostream &operator<<(std::ostream &o, Bureaucrat const &other);

#endif
