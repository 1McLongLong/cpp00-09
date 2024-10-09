#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include <iostream>
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {  
public:
  MateriaSource();
  MateriaSource(const MateriaSource &copy);
  MateriaSource &operator=(const MateriaSource &copy);
  ~MateriaSource();
};


#endif
