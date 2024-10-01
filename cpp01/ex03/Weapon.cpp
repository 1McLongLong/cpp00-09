/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touahman <touahman@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 23:50:14 by touahman          #+#    #+#             */
/*   Updated: 2024/07/25 23:50:15 by touahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) {
  this->type = type;
}

void Weapon::setType(std::string newType) {
  type = newType;
}

const std::string& Weapon::getType() {
  return type;
}
