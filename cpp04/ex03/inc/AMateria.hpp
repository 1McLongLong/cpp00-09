#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>


class ICharacter;

class AMateria {
protected:
  std::string type;
  unsigned int xp;
public:
  AMateria();
  AMateria(const AMateria &copy);
  AMateria &operator=(const AMateria &copy);
  ~AMateria();

  AMateria(std::string const & type);

  std::string const &getType() const; //Returns the materia type
  virtual AMateria* clone() const = 0;
  virtual void use(ICharacter& target);
};


#endif
