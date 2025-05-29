#include "easyfind.hpp"


template <typename T>
void printContainer(T &container) {
  for (typename T::iterator it = container.begin(); it != container.end(); it++)
    std::cout << *it << " ";
  std::cout << std::endl;
}

int main(void)
{
  std::vector<int>  v;
  std::deque<int>   d;
  std::list<int>    l;

  for (int i = 1; i <= 10; i++)
  {
    v.push_back(i);
    d.push_back(i);
    l.push_back(i);
  }

  try {
    std::vector<int>::iterator it = easyfind(v, 10);
    std::cout << *it << " is in V Vector!" << std::endl;
  }
  catch(const std::exception& e) {
    std::cerr << e.what() << '\n';
  }
  try {
    std::deque<int>::iterator it = easyfind(d, 10);
    std::cout << *it << " is in D Deque!" << std::endl;
  }
  catch(const std::exception& e) {
    std::cerr << e.what() << '\n';
  }
  try {
    std::list<int>::iterator it = easyfind(l, 10);
    std::cout << *it << " is in L List!" << std::endl;
  }
  catch(const std::exception& e) {
    std::cerr << e.what() << '\n';
  }
  try {
    std::list<int>::iterator it = easyfind(l, 100);
    std::cout << *it << " is in L List!" << std::endl;
  }
  catch(const std::exception& e) {
    std::cerr << e.what() << '\n';
  }
  return 0;
}

