/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touahman <touahman@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 08:34:38 by touahman          #+#    #+#             */
/*   Updated: 2024/09/16 08:47:33 by touahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

