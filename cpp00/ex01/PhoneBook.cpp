/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touahman <touahman@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 08:53:09 by touahman          #+#    #+#             */
/*   Updated: 2024/09/16 08:55:06 by touahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"


void PhoneBook::init() {
  max = 0;
  n_contacts = 0;
  total_contact = 0;
}


void PhoneBook::set_contact() {
  contacts[n_contacts].set_first_name();
  contacts[n_contacts].set_last_name();
  contacts[n_contacts].set_nick_name();
  contacts[n_contacts].set_phone_number();
  contacts[n_contacts].set_darkest_secret();
  contacts[n_contacts].set_contact_index(n_contacts + 1);
  std::cout << "New contact is added to the phonebook [" << contacts[n_contacts].get_index() << "/8]\n";

  n_contacts = (n_contacts + 1) % 8;
  if (total_contact < 8) {
    total_contact++;
  }
  if (n_contacts == 0) {
    max = 1;
  }
}

void PhoneBook::get_list() {
  if (total_contact == 0)
    std::cout << "There are no available users, but you can (ADD) one!\n";
  else
  {
    display_list();
    std::string str;
    std::cout << "Select an index: ";
    while (1)
    {
      std::getline(std::cin, str);
      if (std::cin.eof())
      {
        std::cout << "\nCioa!\n";
        exit(1);
      }
      int i = atoi(str.c_str());
      if (i > 0 && i < total_contact + 1) {
        contacts[i - 1].get_contact();
        break;
      }
      else {
        std::cout << "Invalid index\nSelect an index: ";
      }
    }
  }
}

void PhoneBook::trimmed_list(const std::string& str) {
  if (str.length() > 10) {
    std::cout << str.substr(0, 9) << ".|";
  } 
  else {
    std::cout << std::setw(10) << str << '|';
  }
}


void PhoneBook::display_list() {
  std::cout << "|     Index|First Name| Last Name|  Nickname|\n";
  int i = 0;
  int k;
  if (max)
    k = 8;
  else 
    k = n_contacts;
  while (i < k) {
    std::cout << '|';
    std::cout << std::setw(10);
    std::cout << contacts[i].get_index() << '|';
    trimmed_list(contacts[i].get_first_name());
    trimmed_list(contacts[i].get_last_name());
    trimmed_list(contacts[i].get_nick_name());
    std::cout << '\n';
    i++;
  }
}
