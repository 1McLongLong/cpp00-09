#include "PresidentialPardonForm.hpp"


void PresidentialPardonForm::execute(const Bureaucrat& b) const {
  std::cout << this->getName() << " was pardoned by President Zaphod Beeblebrox.." << '\n';
}



