#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("default", 145, 137), target("test")
{}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm(target, 145, 137), target(target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) {
  *this = copy;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy) {
  AForm::operator=(copy);
  this->target = copy.target;
  return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

 
void ShrubberyCreationForm::execute(const Bureaucrat& b) const {
  if (!this->getSigned() && b.getGrade() > this->getSignGrade()) {
    throw AForm::GradeTooLowException();
  }
  std::ofstream new_file(target);
  if (!new_file.is_open()) {
    std::cerr << "error opening file\n";
    exit(EXIT_FAILURE);
  }

  std::string Art = 
    "          .     .  .      +     .      .          .\n"
    "     .       .      .     #       .           .\n"
    "        .      .         ###            .      .      .\n"
    "      .      .   \"#:. .:##\"##:. .:#\"  .      .\n"
    "          .      . \"####\"###\"####\"  .\n"
    "       .     \"#:.    .:#\"###\"#:.    .:#\"  .        .       .\n"
    "  .             \"#########\"#########\"        .        .\n"
    "        .    \"#:.  \"####\"###\"####\"  .:#\"   .       .\n"
    "     .     .  \"#######\"\"##\"##\"\"#######\"                  .\n"
    "                .\"##\"#####\"#####\"##\"           .      .\n"
    "    .   \"#:. ...  .:##\"###\"###\"##:.  ... .:#\"     .\n"
    "      .     \"#######\"##\"#####\"##\"#######\"      .     .\n"
    "    .    .     \"#####\"\"#######\"\"#####\"    .      .\n"
    "            .     \"      000      \"    .     .\n"
    "       .         .   .   000     .        .       .\n"
    ".. .. ..................O000O........................ ......\n";
  new_file << Art;
  new_file.close();
}



