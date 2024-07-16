#include <cctype>
#include <iostream>

void to_upper(std::string str)
{
  int i = 0;
  while (str[i] != '\0')
  {
    str[i] = toupper(str[i]);
    i++;
  }
  std::cout << str;
}

int main (int argc, char **argv)
{
  if (argc == 1)
  {
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
    return 0;
  }
  else if (argc > 1)
  {
    for (int i = 1; argv[i]; i++)
      to_upper(argv[i]);
  }
  std::cout << '\n';
  return 0;
}
























