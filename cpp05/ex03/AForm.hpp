#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>

class Bureaucrat;

class AForm {
  const std::string name;
  const int         signGrade;
  const int         signExec;
  bool              _signed;

public:
  AForm();
  AForm(std::string name, int sGrade, int eGrade);
  AForm(const AForm &copy);
  AForm &operator=(const AForm &copy);
  ~AForm();
  class GradeTooHighException : public std::exception {
    const char* what() const throw();
  };
  class GradeTooLowException : public std::exception {
    const char* what() const throw();
  };
  class FormNotSigned : public std::exception {
    const char* what() const throw();
  };
  std::string   getName() const;
  bool          getSigned() const;
  int           getSignGrade() const;
  int           getSignExec() const;
  void          beSigned(Bureaucrat &obj);
  virtual void  execute(const Bureaucrat& b) const = 0;
};

std::ostream    &operator<<(std::ostream &out, const AForm &obj);


#endif
