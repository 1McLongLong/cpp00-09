#ifndef RPN_HPP
# define RPN_HPP


#include <string>
#include <stack>
#include <iostream>
#include <exception>
#include <cstdlib>

class RPN {
  std::stack<int> st;
public:
  RPN();
  RPN(RPN const &src);
  RPN &operator=(RPN const &rhs);
  ~RPN();

  void calculate(char **argv);

};








#endif
