#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>


class Bureaucrat {
  const std::string name;
  int               grade;

public:
  std::string getName() const;
  int         getGrade() const;
  void        GradeTooHighException();
  void        GradeTooLowException();
  void        incGrade();
  void        decGrade();
  Bureaucrat(std::string name, int grade);
};



std::ostream &operator<<(std::ostream &o, Bureaucrat const &other);

#endif
