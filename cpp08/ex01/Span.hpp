#ifndef SPAN_HPP
#define SPAN_HPP


#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <stdexcept>

class Span {
  std::vector<int>  _vector;
  unsigned int      size;

public:
  Span();
  Span(unsigned int N);
  Span(const Span &other);
  Span &operator=(const Span &other);
  ~Span();

  void          addNumber(int number);
  unsigned int  shortestSpan() const;
  unsigned int  longestSpan()  const;
  template <typename T>
    void addNumber(T begin, T end) { 
      for (T it = begin; it != end; it++) 
        addNumber(*it); 
    }
};







#endif
