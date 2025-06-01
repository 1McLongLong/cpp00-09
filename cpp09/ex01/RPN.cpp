#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(RPN const &src) {
  *this = src;
}

RPN &RPN::operator=(RPN const &rhs) {
  (void)rhs;
  return *this;
}

RPN::~RPN() {}


void RPN::calculate(char **argv) {
  std::string str(argv[1]);
  for (size_t i = 0; i < str.length(); i++) {
    if (isdigit(str[i])) {
      if (i + 1 < str.length() && isdigit(str[i + 1])) {
        throw std::runtime_error("Error: number bigger than 9");
      }
      st.push(str[i] - '0');
    }
    else if (str[i] == ' ' || str[i] == '\t') {
      continue;
    }
    else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/') {
      if (st.size() < 2) {
        throw std::runtime_error("Error");
      }
      int num1 = st.top();
      st.pop();
      int num2 = st.top();
      st.pop();
      switch (str[i]) {
        case '+': st.push(num2 + num1); break;
        case '-': st.push(num2 - num1); break;
        case '*': st.push(num2 * num1); break;
        case '/':
          if (num1 == 0)
            throw std::runtime_error("Error: division by zero");
          st.push(num2 / num1);
          break;
      }
    }
    else {
      throw std::runtime_error(std::string("Error: invalid character '") + str[i] + "'");
    }
  }
  if (st.size() != 1) {
    throw std::runtime_error("Error: Wrong calculation");
  }
  std::cout << st.top() << std::endl;
}
