/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touahman <touahman@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 23:50:01 by touahman          #+#    #+#             */
/*   Updated: 2024/07/25 23:50:02 by touahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP


#include <iostream>
#include "Weapon.hpp"

class HumanB {
  Weapon     *m_weapon;
  std::string m_name;
  
  public:
  HumanB(std::string name);
  ~HumanB(void);
  void attack(void);
  void setWeapon(Weapon &weapon);
};

#endif
