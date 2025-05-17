#include "ScalarConverter.hpp"



int	main(int ac, char **av)
{
  if (ac == 2)
    ScalarConverter::convert(av[1]);
  else
    std::cerr << "Error: wrong number of arguments" << std::endl;
}
