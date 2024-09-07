#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "Animal.hpp"


class WrongCat : public Animal {
  public:
    WrongCat();
    WrongCat(const WrongCat &copy);
    WrongCat &operator=(const WrongCat &copy);
    virtual ~WrongCat();

    virtual void makeSound() const;
};


#endif


