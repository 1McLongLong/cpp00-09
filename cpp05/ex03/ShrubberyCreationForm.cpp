#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("default", 145, 137), target("test")
{}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm(target, 145, 137), target(target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy), target(copy.target)
{}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy) {
  AForm::operator=(copy);
  this->target = copy.target;
  return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

 
void ShrubberyCreationForm::execute(const Bureaucrat& b) const {
  if (!this->getSigned())
    throw AForm::FormNotSigned();
  if (b.getGrade() <= this->getSignExec()) {
    std::string file_name = target + "_shrubbery";
    std::ofstream new_file(file_name.c_str());
    if (!new_file.is_open()) {
      throw std::runtime_error("error opening file");
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
  else {
    throw AForm::GradeTooLowException();
  }
}



