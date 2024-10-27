/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touahman <touahman@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 23:48:23 by touahman          #+#    #+#             */
/*   Updated: 2024/07/25 23:49:07 by touahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
 

HumanA::HumanA(std::string name, Weapon &weapon) 
  : m_name(name), m_weapon(weapon)
{}

void HumanA::attack() {
  std::cout << m_name << " attacks with their " << m_weapon.getType() << '\n';
}


HumanA::~HumanA(void) {
  std::cout << "HumanA " << m_name << " is destroyed\n";
}
