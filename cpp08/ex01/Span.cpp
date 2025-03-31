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


unsigned int  Span::shortestSpan() const {
  if (_vector.size() <= 1)
    throw std::runtime_error("Span is too small");
  std::vector<int> tmp = _vector;
  std::sort(tmp.begin(), tmp.end());
  long long minSpan = std::numeric_limits<long long>::max();
  for (size_t i = 0; i < tmp.size() - 1; i++) {
    long long diff = static_cast<long long>(tmp[i + 1]) - tmp[i]; 
    if (diff < minSpan) minSpan = diff;
  }
  return static_cast<unsigned int>(minSpan);
}


unsigned int  Span::longestSpan()  const {
  if (_vector.size() <= 1)
    throw std::runtime_error("Span is too small");
  std::vector<int> tmp = _vector;
  std::sort(tmp.begin(), tmp.end());
  return static_cast<unsigned int>(tmp[tmp.size() - 1] - tmp[0]);
}




