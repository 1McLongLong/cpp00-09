#include "../inc/AMateria.hpp"
#include "../inc/Ice.hpp"
#include "../inc/Cure.hpp"
#include "../inc/Character.hpp"
#include "../inc/MateriaSource.hpp"



void f() {
	system("leaks inter");
}

/* int main() {
  // atexit(f);
  IMateriaSource* src = new MateriaSource();
  src->learnMateria(new Ice());
  src->learnMateria(new Cure());
  
  ICharacter* me = new Character("me");
  
  AMateria* tmp;
  tmp = src->createMateria("ice");
  AMateria* tmp1 = src->createMateria("cure");
  AMateria* tmp2 = src->createMateria("ice");
  AMateria* tmp3 = src->createMateria("ice");
  AMateria* tmp4 = src->createMateria("cure"); // 5
  AMateria* tmp5 = src->createMateria("cure");
  me->equip(tmp);
  me->equip(tmp1);
  me->equip(tmp2);
  me->equip(tmp3);
  me->equip(tmp4);
  me->equip(tmp5);

  tmp = src->createMateria("cure");
  me->equip(tmp);
  
  ICharacter* bob = new Character("bob");
  me->use(0, *bob);
  me->use(1, *bob);

  delete bob;
  delete me;
  delete src;
  
  return 0;
} */



static void subjectTest(){
  IMateriaSource* src = new MateriaSource();
  src->learnMateria(new Ice());
  src->learnMateria(new Cure());
  ICharacter* me = new Character("me");
  AMateria* tmp;
  tmp = src->createMateria("ice");
  me->equip(tmp);
  tmp = src->createMateria("cure");
  me->equip(tmp);
  ICharacter* bob = new Character("bob");
  me->use(0, *bob);
  me->use(1, *bob);
  delete bob;
  delete me;
  delete src;
}

static void cloneTypesTest(){
  AMateria* ptrCure = new Cure();;
  AMateria* ptrIce = new Ice();

  std::cout << "ptrCure type: " << ptrCure->getType() << std::endl;
  std::cout << "ptrIce type: " << ptrIce->getType() << std::endl;

  AMateria* cloneCure = ptrCure->clone();
  AMateria* cloneIce = ptrIce->clone();

  std::cout << "cloneCure type: " << cloneCure->getType() << std::endl;
  std::cout << "cloneIce type: " << cloneIce->getType() << std::endl;

  delete ptrCure;
  delete ptrIce;
  delete cloneCure;
  delete cloneIce;
}

static void	characterBehaviors(){
  ICharacter* ptrCharac = new Character("Dexter");
  std::cout << "Name of character :" << ptrCharac->getName() << std::endl;
  AMateria* ptrM1 = new Cure;
  AMateria* ptrM2 = new Ice;
  AMateria* ptrM3 = ptrM1->clone();
  AMateria* ptrM4 = ptrM2->clone();

  ptrCharac->unequip(2);

  ptrCharac->equip(ptrM1);
  ptrCharac->equip(ptrM2);
  ptrCharac->equip(ptrM3);
  ptrCharac->equip(ptrM4);

  ptrCharac->equip(NULL);
  AMateria* extraM = new Cure;
  ptrCharac->equip(extraM);

  ptrCharac->use(0, *ptrCharac);
  ptrCharac->use(1, *ptrCharac);

  ptrCharac->unequip(-1337);
  ptrCharac->unequip(0);
  ptrCharac->unequip(1);
  ptrCharac->unequip(2);
  ptrCharac->unequip(3);
  ptrCharac->unequip(3);

  delete ptrM1;
  delete ptrM2;
  delete ptrM3;
  delete ptrM4;
  delete ptrCharac; // problem
  delete extraM;
}

static void	characterDeepCopy(){
  Character a;
  {
    Character b = a;
  }
}

int main()
{
  atexit(f);
  subjectTest();
  std::cout << "-------------------------------------------------- End of test." << std::endl;
  cloneTypesTest();
  std::cout << "-------------------------------------------------- End of test." << std::endl;
  characterBehaviors();
  std::cout << "-------------------------------------------------- End of test." << std::endl;
  characterDeepCopy();
  std::cout << "-------------------------------------------------- End of test." << std::endl;
  return 0;
}
