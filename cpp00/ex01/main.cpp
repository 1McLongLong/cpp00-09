#include "PhoneBook.hpp"
#include <iostream>

void add_contact(PhoneBook& phonebook)
{
  phonebook.set_contact();
  std::cout << "You just made the LIST!\n";
}

void get_contact(PhoneBook& phonebook)
{
  phonebook.get_contact();
}

int main(int argc, char **argv)
{
  PhoneBook phonebook;
  std::string command;
  while (1)
  {
    std::cout << "Enter a Command: ";
    std::cin >> command;
    if (command == "ADD")
    {
      add_contact(phonebook);
    }
    else if (command == "SEARCH")
    {
      get_contact(phonebook);
    }
    else if (command == "EXIT") {
      std::cout << "I'm afraid you have to LEAVE!\n";
      exit(1);
    }
  }
}
