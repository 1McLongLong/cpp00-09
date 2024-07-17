#include "PhoneBook.hpp"
#include "Contact.hpp"

int PhoneBook::n_contacts = 0;

void PhoneBook::set_contact()
{
  max = 0;
  if (n_contacts >= 8)
  {
    n_contacts = 0;
    max = 1;
  }
  contacts[n_contacts].set_first_name();
  contacts[n_contacts].set_last_name();
  contacts[n_contacts].set_nick_name();
  contacts[n_contacts].set_phone_number();
  contacts[n_contacts].set_darkest_secret();
  contacts[n_contacts].set_contact_index(n_contacts + 1);

  std::cout << contacts[n_contacts].get_first_name()<<" is added to the phonebook [" << contacts[n_contacts].get_index() << "/8]\n";
  n_contacts++;
}

void PhoneBook::get_list()
{
  if (n_contacts == 0)
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
      if (i > 0 && i < n_contacts + 1) {
        contacts[i - 1].get_contact();
        break;
      }
      else {
        std::cout << "Invalid index\nSelect an index: ";
      }
    }
  }
}

void PhoneBook::display_list()
{
  std::cout << "|     Index|First Name| Last Name|  Nickname|\n";
  int i = 0;
  int k;
  if (max)
    k = 8;
  else 
    k = n_contacts;
  while (i < k)
  {
    std::cout << '|';
    std::cout << std::setw(10);
    std::cout << contacts[i].get_index() << '|';
    if (contacts[i].get_first_name().length() > 10) {
      std::string str = contacts[i].get_first_name();
      str = str.substr(0, 9);
      str.insert(9, ".");
      std::cout << str << '|';
    }
    else { 
      std::cout << std::setw(10);
      std::cout << contacts[i].get_first_name() << '|';
    }
    if (contacts[i].get_last_name().length() > 10) {
      std::string str = contacts[i].get_last_name();
      str = str.substr(0, 9);
      str.insert(9, ".");
      std::cout << str << '|';
    }
    else { 
      std::cout << std::setw(10);
      std::cout << contacts[i].get_last_name() << '|';
    }
    if (contacts[i].get_nick_name().length() > 10) {
      std::string str = contacts[i].get_nick_name();
      str = str.substr(0, 9);
      str.insert(9, ".");
      std::cout << str << "|\n";
    }
    else { 
      std::cout << std::setw(10);
      std::cout << contacts[i].get_nick_name() << "|\n";
    }
    i++;
  }
}
