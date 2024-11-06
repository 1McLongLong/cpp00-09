#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name) {
  if (N <= 0) {
    std::cout << "Give another number\n";
    exit(1);
  }
  Zombie *zombies = new Zombie[N];
  int i = 0;
  while (i < N) {
    zombies[i].set_Name(name);
    i++;
  }
  return zombies;
}
