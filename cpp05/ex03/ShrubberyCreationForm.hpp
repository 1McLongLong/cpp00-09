#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP


#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : AForm {
  std::string target;
public:
  ShrubberyCreationForm();
  ShrubberyCreationForm(std::string target);
  ShrubberyCreationForm(const ShrubberyCreationForm &copy);
  ShrubberyCreationForm &operator=(const ShrubberyCreationForm &copy);
  ~ShrubberyCreationForm();
  void execute(const Bureaucrat& b) const;
};






#endif
