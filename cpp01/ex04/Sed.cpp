#include "Sed.hpp"
#include <string>

Sed::Sed(std::string &file, std::string &s1, std::string &s2) 
  : filename(file), str1(s1), str2(s2)
{}

void Sed::replace_string(std::string &str, std::string &str1,std::string &str2)
{
  size_t pos = str.find(str1); 
  while (pos != std::string::npos) { 
    str.erase(pos, str1.size());
    str.insert(pos, str2);

    pos = str.find(str1, pos + str2.size()); 
  }
}

int Sed::sed_string()
{
  std::string line;
  std::string str;
  std::ifstream file(filename);
  if (!file.is_open()) 
    return 1;
  
  std::ofstream new_file(filename + ".replace");
  if (!file.is_open()) 
    return 1;

  while (std::getline(file, line))
  {
    str += line;
    str += '\n';
  }
  replace_string(str, str1, str2);
  new_file << str;

  return 0;
}
