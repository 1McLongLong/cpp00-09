#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

class Bureaucrat;

class Form {
  const std::string name;
  const int         signGrade;
  const int         signExec;
  bool              _signed;

public:
  Form();
  Form(std::string name, int sGrade, int eGrade);
  Form(const Form &copy);
  Form &operator=(const Form &copy);
  ~Form();
  class GradeTooHighException : public std::exception {
    const char* what() const throw();
  };
  class GradeTooLowException : public std::exception {
    const char* what() const throw();
  };
  std::string   getName() const;
  bool          getSigned() const;
  int           getSignGrade() const;
  int           getSignExec() const;
  void          beSigned(Bureaucrat &obj);
};

std::ostream &operator<<(std::ostream &out, const Form &obj);


#endif
