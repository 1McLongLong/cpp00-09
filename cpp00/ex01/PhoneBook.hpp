#pragma once

#include "Contact.hpp"
#include <iomanip>
#include <cctype>

class PhoneBook {
  Contact contacts[8];
  static int n_contacts;
  int max;
  public:
   void set_contact();
   void get_list();
   void display_list();
};
