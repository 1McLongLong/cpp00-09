#ifndef CURE_HPP
#define CURE_HPP

#include <iostream>

class Cure {
  std::string type;
public:
  Cure();
  Cure(const Cure &copy);
  Cure &operator=(const Cure &copy);
  ~Cure();
  
  Cure *clone();
};


#endif
