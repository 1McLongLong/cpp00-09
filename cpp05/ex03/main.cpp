#include "AForm.hpp"
#include "Intern.hpp"

int main() {
  Intern someIntern;

  try {
    AForm* form1 = someIntern.makeForm("shrubbery creation", "Garden");
    std::cout << "Form1 created: " << form1->getName() << std::endl;
    delete form1;
  }
  catch (const std::exception& e) {
    std::cerr << "Error while creating shrubbery form: " << e.what() << std::endl;
  }

  try {
    AForm* form2 = someIntern.makeForm("robotomy request", "Bender");
    std::cout << "Form2 created: " << form2->getName() << std::endl;
    delete form2;
  }
  catch (const std::exception& e) {
    std::cerr << "Error while creating robotomy form: " << e.what() << std::endl;
  }

  try {
    AForm* form3 = someIntern.makeForm("presidential pardon", "Fry");
    std::cout << "Form3 created: " << form3->getName() << std::endl;
    delete form3;
  } 
  catch (const std::exception& e) {
    std::cerr << "Error while creating presidential form: " << e.what() << std::endl;
  }

  try {
    AForm* form4 = someIntern.makeForm("undefined form", "Nobody");
    std::cout << "Form4 created: " << form4->getName() << std::endl;
    delete form4;
  }
  catch (const std::exception& e) {
    std::cerr << "Error while creating unknown form: " << e.what() << std::endl;
  }

  return 0;
}
