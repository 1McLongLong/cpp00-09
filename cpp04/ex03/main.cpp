#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"


int main() {
  IMateriaSource* src = new MateriaSource();
  src->learnMateria(new Ice());
  src->learnMateria(new Cure());
  
  ICharacter* me = new Character("me");
  
  AMateria* tmp;
  tmp = src->createMateria("ice");
  AMateria* tmp1 = src->createMateria("cure");
  AMateria* tmp2 = src->createMateria("ice");
  AMateria* tmp3 = src->createMateria("ice");
  AMateria* tmp4 = src->createMateria("cure");
  AMateria* tmp5 = src->createMateria("cure");
  me->equip(tmp);
  me->equip(tmp1);
  me->equip(tmp2);
  me->equip(tmp3);
  me->equip(tmp4);
  me->equip(tmp5);
  
  ICharacter* bob = new Character("bob");
  me->use(0, *bob);
  me->unequip(0);
  me->use(1, *bob);
  me->unequip(1);

  delete tmp;
  delete tmp1;
  delete bob;
  delete me;
  delete src;
  
  return 0;
}

