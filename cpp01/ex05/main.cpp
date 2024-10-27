/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touahman <touahman@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 20:15:47 by touahman          #+#    #+#             */
/*   Updated: 2024/07/27 20:15:49 by touahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"


int main() {
  Harl h;

  h.complain("DEBUG");
  h.complain("INFO");
  h.complain("WARNING");
  h.complain("ERROR");

  return 0;
}
