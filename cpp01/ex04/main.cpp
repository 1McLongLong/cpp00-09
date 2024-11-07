/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touahman <touahman@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 18:50:42 by touahman          #+#    #+#             */
/*   Updated: 2024/07/27 18:50:43 by touahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"


int main(int argc, char **argv)
{
  if (argc != 4) {
    std::cout << "Wrong input\n";
    exit(1);
  }
  std::string file = argv[1];
  std::string str1 = argv[2];
  std::string str2 = argv[3];
  if (str1.empty()) {
    std::cout << "Please provide a string to replace!\n";
    exit(1);
  }

  Sed replace(file, str1, str2);
  if (replace.sed_string()) {
    std::cout << "Could not open the file!\n";
    exit(1);
  }
  return 0;
}
