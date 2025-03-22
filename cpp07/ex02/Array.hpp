#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>

template <typename T>
class Array {
  T* _array;
  int _size;
  public:
  Array() : _array(NULL), _size(0) {}
  Array(unsigned int n) : _array(new T[n]), _size(n) {}
  Array(const Array &copy) : _array(new T[copy._size]), _size(copy._size) {
    for (int i = 0; i < _size; i++) {
      _array[i] = copy._array[i];
    }
  }
  Array &operator=(const Array &copy) {
    if (this != &copy) {
    delete[] _array;
    _size = copy._size;
    _array = new T[copy._size];
    for (int i = 0; i < _size; i++) {
      _array[i] = copy._array[i];
    }
    }
    return *this;
  }
  ~Array() {
    delete[] _array; 
  }

  T &operator[](int index) {
    if (index < 0 || index >= _size) {
      throw std::out_of_range("Index out of range");
    }
    return _array[index];
  }
  const T &operator[](int index) const {
    if (index < 0 || index >= _size) {
      throw std::out_of_range("Index out of range");
    }
    return _array[index];
  }

  unsigned int size() const { return _size; }
};


#endif
