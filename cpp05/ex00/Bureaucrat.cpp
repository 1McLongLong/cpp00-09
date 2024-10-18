#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade): name(name),  grade(grade) {
  if (this->grade > 150)
    throw Bureaucrat::GradeTooLowException();
  if (this->grade < 1)
    throw Bureaucrat::GradeTooHighException();
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
  return "Grade is TOO HIGH";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
  return "Grade is TOO LOW";
}


void Bureaucrat::incGrade() {
  if (this->grade >= 150 || this->grade <= 1) {
    std::cout << "Can't increment Grade\n";
    return ;
  }
  this->grade -= 1;
}

void Bureaucrat::decGrade() {
  if (this->grade >= 150 || this->grade <= 1) {
    std::cout << "Can't decrement Grade\n";
    return ;
  }
  this->grade += 1;
}

std::ostream &operator<<(std::ostream &o, Bureaucrat const &other)
{
  o << other.getName() << ", Bureaucrat grade " << other.getGrade();
  return o;
}
    
std::string Bureaucrat::getName() const { return this->name; }

int         Bureaucrat::getGrade() const { return this->grade; }


