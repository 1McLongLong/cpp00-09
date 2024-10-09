#ifndef CURE_HPP
#define CURE_HPP

#include <iostream>
#include "AMateria.hpp"

class Cure : public AMateria {
public:
  Cure();
  Cure(const Cure &copy);
  Cure &operator=(const Cure &copy);
  ~Cure();
 
  virtual Cure* clone() const;
	virtual void use(ICharacter& target); 
};


#endif
