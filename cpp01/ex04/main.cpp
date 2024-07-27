#include "Sed.hpp"


int main(int argc, char **argv)
{
  if (argc != 4)
  {
    std::cout << "Wrong input\n";
    return 1;
  }
  std::string file = argv[1];
  std::string str1 = argv[2];
  std::string str2 = argv[3];

  Sed replace(file, str1, str2);
  if (replace.sed_string())
  {
    std::cout << "Could not open the file!\n";
    return 1;
  }
  return 0;
}
