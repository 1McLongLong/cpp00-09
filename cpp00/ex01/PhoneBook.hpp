#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Contact.hpp"
#include <iomanip>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <iostream>

class PhoneBook {
  Contact contacts[8];
  static int n_contacts;
  int max;
  public:
   void set_contact();
   void get_list();
   void display_list();
};

#endif
