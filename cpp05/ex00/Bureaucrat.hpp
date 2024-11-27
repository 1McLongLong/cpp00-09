#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat {
  const std::string name;
  int   grade;
public:
  Bureaucrat(std::string name, int grade);
  ~Bureaucrat();
  std::string getName() const;
  int         getGrade() const;
  void incGrade();
  void decGrade();

};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &obj);

#endif
