#include "Zombie.hpp"


int main() {
  int len = 2;
  int i = 0;
  Zombie *new_zombie = zombieHorde(len, "Foo");
  while (i < len) {
    new_zombie[i].announce();
    i++;
  }
  delete[] new_zombie;
  return 0;
}
