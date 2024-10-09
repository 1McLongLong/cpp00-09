#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

class ICharacter;

class AMateria {
protected:
  std::string type;
public:
  AMateria();
  AMateria(std::string type);
  AMateria(const AMateria &copy);
  AMateria &operator=(const AMateria &copy);
  ~AMateria();

  AMateria(std::string const & type);

  std::string const &getType() const; //Returns the materia type
  virtual AMateria* clone() const;
  virtual void use(ICharacter& target);
};


#endif
