#ifndef PRESIENTIALPARDONFORM_HPP
#define PRESIENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : AForm {
  std::string target;
public:
  PresidentialPardonForm();
  PresidentialPardonForm(std::string target);
  PresidentialPardonForm(const PresidentialPardonForm &copy);
  PresidentialPardonForm &operator=(const PresidentialPardonForm &copy);
  ~PresidentialPardonForm();
  void execute(const Bureaucrat& b) const;
};




#endif
