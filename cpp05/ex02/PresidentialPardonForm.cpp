#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("default", 25, 5), target("test")
{}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm(target, 25, 5), target(target)
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : AForm(copy), target(copy.target)
{}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &copy) {
  AForm::operator=(copy);
  this->target = copy.target;
  return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{}

void PresidentialPardonForm::execute(const Bureaucrat& b) const {
  if (!this->getSigned())
    throw AForm::FormNotSigned();
  if (b.getGrade() <= this->getSignExec())
    std::cout << this->getName() << " was pardoned by President Zaphod Beeblebrox." << '\n';
  else
    throw AForm::GradeTooLowException();
}

