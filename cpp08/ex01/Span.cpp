#include "Span.hpp"


Span::Span() {}

Span::Span(unsigned int N) : size(N) {}
  
Span::Span(const Span &other) {
  *this = other;
}

Span &Span::operator=(const Span &other) {
  if (this != &other) {
    this->_vector = other._vector;
    this->size = other.size;
  }
  return *this;
}

Span::~Span() {}

void  Span::addNumber(int number) {
  if (_vector.size() < size) {
    _vector.push_back(number);
  }
  else 
    throw std::runtime_error("Span is full");
}

size_t  Span::shortestSpan() const {
  if (_vector.size() <= 1)
    throw std::runtime_error("Span is too small");
  
  std::vector<int> tmp = _vector;
  std::sort(tmp.begin(), tmp.end());
  
  size_t minSpan = std::numeric_limits<size_t>::max();
  for (size_t i = 0; i < tmp.size() - 1; i++) {
    size_t diff = static_cast<size_t>(tmp[i + 1] - tmp[i]);
    if (diff < minSpan) 
      minSpan = diff;
  }
  return minSpan;
}


size_t  Span::longestSpan()  const {
  if (_vector.size() <= 1)
    throw std::runtime_error("Span is too small");
  std::vector<int> tmp = _vector;
  std::sort(tmp.begin(), tmp.end());
  return tmp[tmp.size() - 1] - tmp[0];
}




