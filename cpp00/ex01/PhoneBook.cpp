#include "PhoneBook.hpp"


int PhoneBook::n_contacts = 0;

void PhoneBook::set_contact()
{
  if (n_contacts < 7) {
    contacts[n_contacts].set_first_name();
    contacts[n_contacts].set_last_name();
    contacts[n_contacts].set_nick_name();
    contacts[n_contacts].set_phone_number();
    contacts[n_contacts].set_darkest_secret();
    contacts[n_contacts].set_contact_index(n_contacts + 1);
    n_contacts++;
  }
  else {
    n_contacts = 0;
    contacts[n_contacts].set_first_name();
    contacts[n_contacts].set_last_name();
    contacts[n_contacts].set_nick_name();
    contacts[n_contacts].set_phone_number();
    contacts[n_contacts].set_darkest_secret();
    n_contacts++;
  }
}

void PhoneBook::get_contact()
{
  int i;
  std::cout << "Select an index: ";
  std::cin >> i;
  while (1)
  {
    if (i > 0 && i < n_contacts + 1) {
      contacts[i - 1].get_contact();
      break;
    }
    else {
      std::cout << "Invalid index\nSelect an index: ";
      std::cin >> i;
    }
  }
}
