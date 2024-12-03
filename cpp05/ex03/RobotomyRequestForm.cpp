#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("default", 72, 45), target("test")
{}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm(target, 72, 45), target(target)
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) {
  *this = copy;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy) {
  AForm::operator=(copy);
  this->target = copy.target;
  return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{}


void RobotomyRequestForm::execute(const Bureaucrat& b) const { 
  if (!this->getSigned() && b.getGrade() > this->getSignGrade()) {
    throw AForm::GradeTooLowException();
  } 
  int tmp = std::rand() % 2; 
  if (tmp) {
    std::cout << this->getName() << " succeeded in becoming a robot" << std::endl;
  }
  else {
    std::cout << "sorry... " << this->getName() << " failed to becoming a robot" << std::endl;
  }
}


