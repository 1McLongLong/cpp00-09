#include "Bureaucrat.hpp"

AForm::AForm() : name("default"), signGrade(0), signExec(0), _signed(0)
{}

AForm::AForm(std::string name, int sGrade, int eGrade) : name(name), signGrade(sGrade), signExec(eGrade), _signed(0)
{}

AForm::AForm(const AForm &copy) : name(copy.name), signGrade(copy.signGrade), signExec(copy.signExec), _signed(copy._signed)
{}

AForm &AForm::operator=(const AForm &copy) {
  this->_signed = copy._signed;
  return *this;
}

AForm::~AForm()
{}

const char* AForm::GradeTooHighException::what() const throw() {
  return "Grade Too High!!!";
}

const char* AForm::GradeTooLowException::what() const throw() {
  return "Grade Too Low!!!";
}

std::string AForm::getName() const {
  return this->name;
}

bool AForm::getSigned() const {
  return this->_signed;
}

int AForm::getSignGrade() const {
  return this->signGrade;
}

int AForm::getSignExec() const {
  return this->signExec;
}

std::ostream &operator<<(std::ostream &out, const AForm &obj) {
  out << obj.getName() << std::boolalpha <<", signed : " << obj.getSigned()
    << ", signGrade : " << obj.getSignGrade()
    << ", execGrade : " << obj.getSignExec();
  return out;
}


void AForm::beSigned(Bureaucrat &obj) {
  if (obj.getGrade() <= signGrade)
    _signed = 1;
  else
    throw GradeTooLowException();
}


