/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touahman <touahman@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 18:50:45 by touahman          #+#    #+#             */
/*   Updated: 2024/07/27 18:50:47 by touahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_HPP
#define SED_HPP

#include <iostream>
#include <fstream>
#include <string>


class Sed {
  std::string filename;
  std::string str1;
  std::string str2;
  void        replace_string(std::string &str, std::string &str1,std::string &str2);

  public:
  Sed(std::string &file, std::string &s1, std::string &s2);
  int         sed_string();
};

#endif
