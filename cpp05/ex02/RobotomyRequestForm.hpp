#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm : public AForm {
  std::string target;
public:
  RobotomyRequestForm();
  RobotomyRequestForm(std::string target);
  RobotomyRequestForm(const RobotomyRequestForm &copy);
  RobotomyRequestForm &operator=(const RobotomyRequestForm &copy);
  ~RobotomyRequestForm();
  void execute(const Bureaucrat& b) const;
};





#endif
