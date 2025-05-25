#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>

template <typename T>
class Array {
  T* arr;
  int arr_size;
public:
  Array() : arr(NULL), arr_size(0) {}
  Array(unsigned int n) : arr(new T[n]), arr_size(n) {}
  Array(const Array &copy) : arr(new T[copy.arr_size]), arr_size(copy.arr_size) {
    for (int i = 0; i < arr_size; i++) {
      arr[i] = copy.arr[i];
    }
  }
  Array &operator=(const Array &copy) {
    if (this != &copy) {
      delete[] arr;
      arr_size = copy.arr_size;
      arr = new T[copy.arr_size];
      for (int i = 0; i < arr_size; i++) {
        arr[i] = copy.arr[i];
      }
    }
    return *this;
  }
  ~Array() {
    delete[] arr; 
  }

  T &operator[](int index) {
    if (index < 0 || index >= arr_size) {
      throw std::out_of_range("Index out of range");
    }
    return arr[index];
  }
  const T &operator[](int index) const {
    if (index < 0 || index >= arr_size) {
      throw std::out_of_range("Index out of range");
    }
    return arr[index];
  }

  unsigned int size() const { return arr_size; }
};


#endif
