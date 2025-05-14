#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("default", 72, 45), target("test")
{}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm(target, 72, 45), target(target)
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm(copy), target(copy.target)
{}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy) {
  AForm::operator=(copy);
  this->target = copy.target;
  return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{}


void RobotomyRequestForm::execute(const Bureaucrat& b) const {
  if (!this->getSigned())
    throw AForm::FormNotSigned();
  if (b.getGrade() > this->getSignExec())
    throw AForm::GradeTooLowException();

  std::cout << "*BZZZT! DRILLING NOISES*" << std::endl;
  static bool seeded = false;
  if (!seeded) {
    std::srand(static_cast<unsigned int>(std::time(0)));
    seeded = true;
  }
  
  int tmp = std::rand() % 2; 
  if (tmp) {
    std::cout << this->getName() << " has been robotomized successfully!" << std::endl;
  }
  else {
    std::cout << "sorry... " << this->getName() << " failed his robotomy!" << std::endl;
  }
}


