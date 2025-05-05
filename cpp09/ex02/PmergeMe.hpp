#ifndef PMERGEME
#define PMERGEME

#include <vector>
#include <deque>
#include <algorithm>
#include <iostream>
#include <exception>
#include <ctime>
#include <iomanip>

class PmergeMe {
  public:
    PmergeMe(int argc, char **argv);
    PmergeMe(const PmergeMe &src);
    PmergeMe &operator=(const PmergeMe &rhs);
    ~PmergeMe();

    void sort();
  private:
    std::vector<int> vector;
    std::deque<int>  deque;
  
    std::vector<int> jacobsthal_number(size_t size);
    
    template <typename Container>
      void mergeInsertionSort(Container &container);
    
    template <typename Container>
      void printContainer(const Container &container);
};

template <typename Container>
void PmergeMe::printContainer(const Container &container) {
  for (size_t i = 0; i < container.size(); ++i)
    std::cout << container[i] << " ";
  std::cout << std::endl;
}


template <typename Container>
void PmergeMe::mergeInsertionSort(Container &container) {
  if (container.size() <= 1)
    return;

  typedef typename Container::value_type T;
  std::vector<std::pair<T, T> > pairs;
  Container sorted;
  size_t check = container.size() % 2;

  for (size_t i = 0; i < container.size() - check; i += 2) {
    if (container[i] > container[i + 1])
      pairs.push_back(std::make_pair(container[i], container[i + 1]));
    else
      pairs.push_back(std::make_pair(container[i + 1], container[i]));
  }

  T odd = T();
  bool has_odd = false;
  if (check) {
    odd = container.back();
    has_odd = true;
  }

  Container large;
  for (size_t i = 0; i < pairs.size(); i++) {
    large.push_back(pairs[i].first);
  }

  mergeInsertionSort(large);
  sorted = large;

  if (!pairs.empty()) {
    typename Container::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), pairs[0].second);
    sorted.insert(pos, pairs[0].second);
  }

  std::vector<int> jacobsthal = jacobsthal_number(pairs.size());
  for (size_t j = 1; j < jacobsthal.size(); j++) {
    for (int i = jacobsthal[j - 1] + 1; i <= jacobsthal[j] && i < static_cast<int>(pairs.size()); i++) {
      typename Container::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), pairs[i].second);
      sorted.insert(pos, pairs[i].second);
    }
  }

  for (size_t i = jacobsthal.back() + 1; i < pairs.size(); i++) {
    typename Container::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), pairs[i].second);
    sorted.insert(pos, pairs[i].second);
  }

  if (has_odd) {
    typename Container::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), odd);
    sorted.insert(pos, odd);
  }

  container = sorted;
}


#endif
