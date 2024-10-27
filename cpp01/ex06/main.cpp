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


int main(int argc, char **argv) {
  if (argc != 2) {
    std::cout  << "Use with: ./HarlFilter (DEBUG | INFO | WARNING | ERROR)\n";
    return 1;
  }
  Harl h;

  h.complain(argv[1]);
  return 0;
}
