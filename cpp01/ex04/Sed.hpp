#ifndef SED_HPP
#define SED_HPP

#include <iostream>
#include <fstream>


class Sed 
{
  std::string filename;
  std::string str1;
  std::string str2;
  void sed_string(std::string &file, std::string &s1, std::string &s2);

  public:
  Sed(std::string &file, std::string &s1, std::string &s2);
};

#endif
