#include "Bureaucrat.hpp"

Form::Form() : name("default"), signGrade(150), signExec(150), _signed(0) {}

Form::Form(std::string name, int sGrade, int eGrade) : name(name), signGrade(sGrade), signExec(eGrade), _signed(0) {
  if (sGrade < 1 || eGrade < 1)
    throw Form::GradeTooHighException();
  else if (sGrade > 150 || eGrade > 150)
    throw Form::GradeTooLowException();
}

Form::Form(const Form &copy) : name(copy.name), signGrade(copy.signGrade), signExec(copy.signExec), _signed(copy._signed)
{}

Form &Form::operator=(const Form &copy) {
  this->_signed = copy._signed;
  return *this;
}

Form::~Form()
{}

const char* Form::GradeTooHighException::what() const throw() {
  return "Grade Too High!!!";
}

const char* Form::GradeTooLowException::what() const throw() {
  return "Grade Too Low!!!";
}

std::string Form::getName() const { return this->name; }

bool Form::getSigned() const { return this->_signed; }

int Form::getSignGrade() const { return this->signGrade; }

int Form::getSignExec() const { return this->signExec; }

std::ostream &operator<<(std::ostream &out, const Form &obj) {
  	out << obj.getName() << std::boolalpha <<", signed : " << obj.getSigned()
		    << ", signGrade : " << obj.getSignGrade()
		    << ", execGrade : " << obj.getSignExec();
  return out;
}


void Form::beSigned(Bureaucrat &obj) {
  if (obj.getGrade() <= signGrade)
    _signed = 1;
  else
    throw Form::GradeTooLowException();
}


