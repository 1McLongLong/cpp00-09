#include "PhoneBook.hpp"

void add_contact(PhoneBook& phonebook)
{
  phonebook.set_contact();
}

void get_contact(PhoneBook& phonebook)
{
  phonebook.get_list();
}

int main(int argc, char **argv)
{
  PhoneBook phonebook;
  std::string command;
  while (1)
  {
    std::cout << "Enter a Command (ADD | SEARCH | EXIT): ";
    std::getline(std::cin,command);
    if (std::cin.eof())
    {
      std::cout << "\nCioa!\n";
      exit(1);
    }
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
      break;
    }
  }
}
