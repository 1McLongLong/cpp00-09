/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touahman <touahman@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 23:49:57 by touahman          #+#    #+#             */
/*   Updated: 2024/07/25 23:49:58 by touahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : m_name(name), m_weapon(NULL)
{
  std::cout << m_name << " created with no weapon\n";
}

void HumanB::setWeapon(Weapon &weapon)
{
  m_weapon = &weapon;
}

void HumanB::attack()
{
  std::cout << m_name << " attacks with their " << m_weapon->getType() << '\n';
}

HumanB::~HumanB(void)
{
  std::cout << "HumanB " << m_name << " is destroyed\n";
}
