#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
{
}

Bureaucrat::~Bureaucrat()
{}

std::string Bureaucrat::getName() const{

}

int Bureaucrat::getGrade() const{

}

void Bureaucrat::incGrade(){

}

void Bureaucrat::decGrade(){

}
std::ostream &operator<<(std::ostream &out, const Bureaucrat &obj) {
  out << obj.getName();
  out << obj.getGrade();
  return out;
}
