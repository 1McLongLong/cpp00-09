/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touahman <touahman@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 23:50:17 by touahman          #+#    #+#             */
/*   Updated: 2024/07/25 23:50:18 by touahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>


class Weapon {
  std::string type;
  
  public:
  Weapon(std::string type);
  void setType(std::string newType);
  const std::string& getType();
};

#endif
