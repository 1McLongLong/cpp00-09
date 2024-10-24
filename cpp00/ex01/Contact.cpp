/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touahman <touahman@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 08:50:08 by touahman          #+#    #+#             */
/*   Updated: 2024/09/16 08:51:02 by touahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

int only_space(std::string &string) {
  int i = 0;
  while (string[i])
  {
    if (string[i] > 32 && string[i] < 127)
      return 0;
    i++;
  }
  return 1;
}

int only_numbers(std::string &string) {
  int i = 0;
  while (string[i])
  {
    if (string[i] < 48 || string[i] > 57)
      return 1;
    i++;
  }
  return 0;
}

void Contact::set_first_name() {
  while (m_first_name.empty())
  {
    std::cout << "Enter your first name: ";
    std::getline(std::cin, m_first_name); 
    if (only_space(m_first_name))
      m_first_name.clear();
    if (std::cin.eof())
    {
      std::cout << "\nCioa!\n";
      exit(1);
    }
  }
}

void Contact::set_last_name() {
  while (m_last_name.empty())
  {
    std::cout << "Enter your last name: ";
    std::getline(std::cin, m_last_name); 
    if (only_space(m_last_name))
      m_last_name.clear();
    if (std::cin.eof())
    {
      std::cout << "\nCioa!\n";
      exit(1);
    }
  }
}

void Contact::set_nick_name() {
  while (m_nick_name.empty())
  {
    std::cout << "Enter your nick name: ";
    std::getline(std::cin, m_nick_name); 
    if (only_space(m_nick_name))
      m_nick_name.clear();
    if (std::cin.eof())
    {
      std::cout << "\nCioa!\n";
      exit(1);
    }
  }
}

void Contact::set_darkest_secret() {
  while (m_darkest_secret.empty())
  {
    std::cout << "Enter your darkest secret: ";
    std::getline(std::cin, m_darkest_secret); 
    if (only_space(m_darkest_secret))
      m_darkest_secret.clear();
    if (std::cin.eof())
    {
      std::cout << "\nCioa!\n";
      exit(1);
    }
  }
}

void Contact::set_phone_number() {
  while (m_phone_number.empty())
  {
    std::cout << "Enter your phone number: ";
    std::getline(std::cin, m_phone_number);
    if (only_space(m_phone_number) || only_numbers(m_phone_number))
      m_phone_number.clear();
    if (std::cin.eof())
    {
      std::cout << "\nCioa!\n";
      exit(1);
    }
  }
}

void Contact::set_contact_index(int index) { m_contact_index = index;}

int Contact::get_index() { return m_contact_index;}
std::string Contact::get_first_name() { return m_first_name;}
std::string Contact::get_last_name() { return m_last_name;}
std::string Contact::get_nick_name() { return m_nick_name;}

void Contact::get_contact() {
  std::cout << "First Name: " << m_first_name << '\n';
  std::cout << "Last Name: " << m_last_name << '\n';
  std::cout << "Nickame: " << m_nick_name << '\n';
  std::cout << "Phone Number: " << m_phone_number << '\n';
  std::cout << "Darkest Secret: " << m_darkest_secret << '\n';
}

