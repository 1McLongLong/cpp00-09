#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade): name(name),  grade(grade) {
  if (this->grade > 150)
    GradeTooLowException();
  if (this->grade < 1)
    GradeTooHighException();
}

void Bureaucrat::GradeTooHighException() {
  std::cout << "Grade is TOO HIGH\n";
}

void Bureaucrat::GradeTooLowException() {
  std::cout << "Grade is TOO LOW\n";
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
  o << other.getName() << ", Bureaucrat grade " << other.getGrade() << '\n';
  return o;
}
    
std::string Bureaucrat::getName() const { return this->name; }

int         Bureaucrat::getGrade() const { return this->grade; }


