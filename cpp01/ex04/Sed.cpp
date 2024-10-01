/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touahman <touahman@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 18:50:34 by touahman          #+#    #+#             */
/*   Updated: 2024/07/27 19:46:44 by touahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

Sed::Sed(std::string &file, std::string &s1, std::string &s2) 
  : filename(file), str1(s1), str2(s2)
{}

void Sed::replace_string(std::string &str, std::string &str1,std::string &str2) {
  size_t pos = str.find(str1); 
  while (pos != std::string::npos) { 
    str.erase(pos, str1.size());
    str.insert(pos, str2);
    pos = str.find(str1, pos + str2.size()); 
  }
}

int Sed::sed_string() {
  std::string   line;
  std::string   str;
  std::ifstream file(filename);
  if (!file.is_open()) 
    return 1;
  
  std::ofstream new_file(filename + ".replace");
  if (!new_file.is_open()) 
    return 1;

  while (std::getline(file, line)) {
    str += line;
    str += '\n';
  }
  replace_string(str, str1, str2);
  new_file << str;
  
  file.close();
  new_file.close();
  
  return 0;
}
