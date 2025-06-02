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
  
    std::vector<int> jacobsthalSequence(size_t size);
    
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

  std::vector<std::pair<int, int> > pairs;
  Container sorted;
  size_t check = container.size() % 2;

  for (size_t i = 0; i < container.size() - check; i += 2) {
    if (container[i] > container[i + 1])
      pairs.push_back(std::make_pair(container[i], container[i + 1]));
    else
      pairs.push_back(std::make_pair(container[i + 1], container[i]));
  }

  int straggler = -1;
  bool has_odd = false;
  if (check) {
    straggler = container.back();
    has_odd = true;
  }

  Container large;
  for (size_t i = 0; i < pairs.size(); i++)
    large.push_back(pairs[i].first);                //////////////////////////////////////   HOW DOES push_back() and insert() work with vector and deque?

  mergeInsertionSort(large);
  sorted = large;

  // insert smaller element
  if (!pairs.empty()) {
    typename Container::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), pairs[0].second);
    sorted.insert(pos, pairs[0].second);
  }

  std::vector<int> jacobsthal = jacobsthalSequence(pairs.size());
  for (size_t j = 1; j < jacobsthal.size(); j++) {
    int start = jacobsthal[j - 1] + 1;   // one past the previous Jacobsthal
    int end   = jacobsthal[j];           // up to (and including) this Jacobsthal
    // Insert all i in [start … end], as long as i < pairs.size()
    for (int i = start; i <= end && i < static_cast<int>(pairs.size()); i++) {
      typename Container::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), pairs[i].second);
      sorted.insert(pos, pairs[i].second);
    }
  }

  int afterJ = jacobsthal.back() + 1;
  for (size_t i = afterJ; i < pairs.size(); i++) {
    typename Container::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), pairs[i].second);
    sorted.insert(pos, pairs[i].second);
  }

  if (has_odd) {
    typename Container::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), straggler);
    sorted.insert(pos, straggler);
  }

  container = sorted;
}


#endif
