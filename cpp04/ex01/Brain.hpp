#ifndef BRAIN_HPP
#define BRAIN_HPP

#include "Animal.hpp"

class Brain {
  std::string ideas[100];
public: 
  Brain();
  Brain(const Brain &copy);
  Brain &operator=(const Brain &copy);
  ~Brain();

};

#endif
