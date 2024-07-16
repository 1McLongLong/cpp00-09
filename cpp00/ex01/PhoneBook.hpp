#pragma once

#include "Contact.hpp"

class PhoneBook {
  Contact contacts[8];
  static int n_contacts;
  public:
   void set_contact();
   void set_index();
   void get_contact();
};
