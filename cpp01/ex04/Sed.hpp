#ifndef SED_HPP
#define SED_HPP

#include <iostream>
#include <fstream>


class Sed 
{
  std::string filename;
  std::string str1;
  std::string str2;
  void replace_string(std::string &str, std::string &str1,std::string &str2);

  public:
  int sed_string();
  Sed(std::string &file, std::string &s1, std::string &s2);
};

#endif
