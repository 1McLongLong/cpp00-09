#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "AMateria.hpp"

struct MateriaNode {
  AMateria    *materia;
  MateriaNode *next;

  MateriaNode(AMateria *materia, MateriaNode *next = NULL)
  : materia(materia), next(next) {}
};

class Character : public ICharacter {
  AMateria	  *slots[4];
  MateriaNode *materiaListHead;
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
  void                      clearMateriaList();
};


#endif
