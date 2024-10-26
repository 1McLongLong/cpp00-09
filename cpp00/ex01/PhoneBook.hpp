/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touahman <touahman@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 09:06:56 by touahman          #+#    #+#             */
/*   Updated: 2024/09/16 09:07:07 by touahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Contact.hpp"
#include <iomanip>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <iostream>

class PhoneBook {
  Contact     contacts[8];
  static int  n_contacts;
  int         max;
public:
  void        trimmed_list(const std::string &str);
  void        set_contact();
  void        get_list();
  void        display_list();
};

#endif
