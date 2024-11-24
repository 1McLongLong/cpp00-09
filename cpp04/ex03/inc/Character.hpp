#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "AMateria.hpp"

class Character : public ICharacter {
  AMateria	  *slots[4];
  std::string name;
public:
  Character();
  Character(std::string name);
  Character(const Character &copy);
  Character &operator=(const Character &copy);
  ~Character();

  virtual std::string const &getName() const;
  virtual void              equip(AMateria* m);
  virtual void              unequip(int idx);
  virtual void              use(int idx, ICharacter& target);
};


#endif
