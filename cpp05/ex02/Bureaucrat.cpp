#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Default"), grade(150) {}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name) {
  if (grade < 1)
    throw GradeTooHighException();
  else if (grade > 150)
    throw GradeTooLowException();
  else
    this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : name(copy.name), grade(copy.grade)
{}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy) {
  this->grade = copy.grade;
  return *this;
}

Bureaucrat::~Bureaucrat()
{}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
  return "Grade Too High!!!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
  return "Grade Too Low!!!";
}

std::string Bureaucrat::getName() const {
  return this->name;
}

int Bureaucrat::getGrade() const {
  return this->grade;
}

void Bureaucrat::incGrade() {
  grade--; 
  if (grade < 1)
    throw GradeTooHighException();
}

void Bureaucrat::decGrade() {
  grade++; 
  if (grade > 150)
    throw GradeTooLowException();
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &obj) {
  out << obj.getName() << ", bureaucrat grade " << obj.getGrade() << '.';
  return out;
}

void Bureaucrat::signForm(AForm &form) {
  try {
    form.beSigned(*this);
    std::cout << name << " signed " << form.getName() << '\n';
  }
  catch (std::exception &e) {
    std::cout << name << " couldn’t sign " << form.getName() << " because " << e.what() << '\n';
  }
}

void Bureaucrat::executeForm(AForm const &form) {
  try {
    form.execute(*this);
    std::cout << name << " executed " << form.getName() << '\n';
  }
  catch (std::exception &e) {
    std::cout << name << " couldn’t execute " << form.getName() << " because " << e.what() << '\n';
  }
}

