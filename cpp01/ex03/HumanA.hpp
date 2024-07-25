/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touahman <touahman@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 23:49:53 by touahman          #+#    #+#             */
/*   Updated: 2024/07/25 23:49:55 by touahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP


#include <iostream>
#include "Weapon.hpp"

class HumanA
{
  Weapon &m_weapon;
  std::string m_name;
  
  public:
  HumanA(std::string name, Weapon &weapon);
  ~HumanA( void );
  void attack( void );
};

#endif
