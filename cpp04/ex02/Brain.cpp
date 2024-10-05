#include "Brain.hpp"

Brain::Brain() {
  std::cout << "Brain constructor\n";
  for (int i = 0; i < 100; i++) {
    ideas[i] = "Idea " + std::to_string(i + 1);
  }
}

Brain::Brain(const Brain &copy) {
  std::cout << "Brain copy constructor constructor is called\n";
  *this = copy;
}

Brain &Brain::operator=(const Brain &copy) {
  std::cout << "Brain Copy assignement operator is called\n";
  if (this != &copy){
    for (int i = 0; i < 100; i++) {
      this->ideas[i] = copy.ideas[i];
    }
  }
  return *this;
}

Brain::~Brain() {
  std::cout << "Brain destructor\n";
}

