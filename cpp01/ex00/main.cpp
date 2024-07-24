#include "Zombie.hpp"

int main()
{
  Zombie *zombie = newZombie("BOO");
  zombie->announce();
  randomChump("FOO");
  delete zombie;
  return 0;
}
