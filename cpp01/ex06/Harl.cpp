/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touahman <touahman@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 22:58:47 by touahman          #+#    #+#             */
/*   Updated: 2024/07/27 23:10:20 by touahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int check_comment(std::string level)
{
  std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
  int i = 0;
  while (i < 4)
  {
    if (levels[i] == level)
    {
      return i;
      break ;
    }
    i++;
  }
  return 4;
}

void Harl::complain( std::string level )
{
  void (Harl::*comments[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
  
  int i = check_comment(level);
  
  switch(i)
  {
    case 0:
      (this->*comments[i])();
      i++;
    case 1:
      (this->*comments[i])();
      i++;
    case 2:
      (this->*comments[i])();
      i++;
    case 3:
      (this->*comments[i])();
      break;
    default:
      std::cout << "[ Probably complaining about insignificant problems ]\n";
      break;
  }
}

void Harl::debug( void )
{
  std::cout << "{DEBUG} :\n";
  std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\n";
}

void Harl::info( void )
 {
  std::cout << "{INFO} :\n";
  std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n";
}

void Harl::warning( void )
{
  std::cout << "{WARNING} :\n";
  std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.\n";
}

void Harl::error( void )
{
  std::cout << "{ERROR} :\n";
  std::cout << "This is unacceptable! I want to speak to the manager now.\n";
}
