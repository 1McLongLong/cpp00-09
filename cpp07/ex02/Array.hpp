#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>

template <typename T>
class Array {
  T* arr;
  size_t arr_size;
public:
  Array() : arr(NULL), arr_size(0) {}
  Array(size_t n) : arr(new T[n]), arr_size(n) {}
  Array(const Array &copy) : arr(new T[copy.arr_size]), arr_size(copy.arr_size) {
    for (size_t i = 0; i < arr_size; i++) {
      arr[i] = copy.arr[i];
    }
  }
  Array &operator=(const Array &copy) {
    if (this != &copy) {
      delete[] arr;
      arr_size = copy.arr_size;
      arr = new T[copy.arr_size];
      for (size_t i = 0; i < arr_size; i++) {
        arr[i] = copy.arr[i];
      }
    }
    return *this;
  }
  ~Array() {
    delete[] arr; 
  }

  T &operator[](size_t index) {
    if (index >= arr_size) {
      throw std::out_of_range("Index out of range");
    }
    return arr[index];
  }
  const T &operator[](size_t index) const {
    if (index >= arr_size) {
      throw std::out_of_range("Index out of range");
    }
    return arr[index];
  }

  size_t size() const { return arr_size; }
};


#endif
