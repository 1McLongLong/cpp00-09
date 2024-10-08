#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include "ICharacter.hpp"


class Character {
  
public:
  Character();
  Character(const Character &copy);
  Character &operator=(const Character &copy);
  ~Character();
  
  virtual std::string const & getName() const = 0;
  virtual void equip(AMateria* m) = 0;
  virtual void unequip(int idx) = 0;
  virtual void use(int idx, ICharacter& target) = 0;
  AMateria *getMateria(int i);
};


#endif
