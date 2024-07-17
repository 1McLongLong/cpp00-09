#include "Contact.hpp"

void Contact::set_first_name()
{
  std::cout << "Enter your first name: ";
  std::getline(std::cin, m_first_name);
}

void Contact::set_last_name()
{
  std::cout << "Enter your last name: ";
  std::getline(std::cin, m_last_name);
}

void Contact::set_nick_name()
{
  std::cout << "Enter your nick name: ";
  std::getline(std::cin, m_nick_name);
}

void Contact::set_darkest_secret()
{
  std::cout << "Enter your darkest secret: ";
  std::getline(std::cin, m_darkest_secret);
}

void Contact::set_phone_number()
{
  std::cout << "Enter your phone number: ";
  std::getline(std::cin, m_phone_number);
}

void Contact::set_contact_index(int index)
{
  m_contact_index = index;
}


int Contact::get_index() { return m_contact_index;}
std::string Contact::get_first_name() { return m_first_name;}
std::string Contact::get_last_name() { return m_last_name;}
std::string Contact::get_nick_name() { return m_nick_name;}

void Contact::get_contact()
{
  std::cout << "First Name: " << m_first_name << '\n';
  std::cout << "Last Name: " << m_last_name << '\n';
  std::cout << "Nickame: " << m_nick_name << '\n';
  std::cout << "Phone Number: " << m_phone_number << '\n';
  std::cout << "Darkest Secret: " << m_darkest_secret << '\n';
}



