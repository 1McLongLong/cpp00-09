#ifndef ICE_HPP
#define ICE_HPP

#include <iostream>

class Ice {
  std::string type;
public:
  Ice();
  Ice(const Ice &copy);
  Ice &operator=(const Ice &copy);
  ~Ice();

  Ice *clone();
};


#endif
