#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("default", 25, 5), target("test")
{}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm(target, 25, 5), target(target)
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) {
  *this = copy;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &copy) {
  AForm::operator=(copy);
  this->target = copy.target;
  return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{}

void PresidentialPardonForm::execute(const Bureaucrat& b) const {
  if (!getSigned() && b.getGrade() > this->getSignGrade())
    throw GradeTooLowException();
  std::cout << this->getName() << " was pardoned by President Zaphod Beeblebrox.." << '\n';
}

