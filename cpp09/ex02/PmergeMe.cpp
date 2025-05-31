#include "PmergeMe.hpp"


PmergeMe::PmergeMe(int argc, char **argv) {
  for (int i = 1; i < argc; i++) {
    int num = std::atoi(argv[i]);
    if (num < 0)
      throw std::runtime_error("Error: negative numbers not allowed");
    vector.push_back(num);
    deque.push_back(num);
  }
}

PmergeMe::PmergeMe(const PmergeMe &src) {
  *this = src;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &rhs) {
  if (this != &rhs) {
    vector = rhs.vector;
    deque = rhs.deque;
  }
  return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::sort() {
  std::cout << "Before: ";
  printContainer(vector);

  std::vector<int> v = vector;
  std::deque<int> d = deque;

  clock_t start_vec = clock();
  mergeInsertionSort(v);
  clock_t end_vec = clock();
  double duration_vec = static_cast<double>(end_vec - start_vec) / (CLOCKS_PER_SEC);
  
  clock_t start_dq = clock();
  mergeInsertionSort(d);
  clock_t end_dq = clock();
  double duration_dq = static_cast<double>(end_dq - start_dq) / (CLOCKS_PER_SEC);

  std::cout << "After: ";
  printContainer(v);

  std::cout << std::fixed << std::setprecision(5);
  std::cout << "Time to process a range of " << v.size() << " elements with std::vector: " << duration_vec << " us" << std::endl;
  std::cout << "Time to process a range of " << d.size() << " elements with std::deque: " << duration_dq << " us" << std::endl;
}

std::vector<int> PmergeMe::jacobsthal_number(size_t size)
{
  std::vector<int> jacobsthal;
  jacobsthal.push_back(0);
  jacobsthal.push_back(1);
  while (1)
  {
    int next = jacobsthal[jacobsthal.size() - 1] + 2 * jacobsthal[jacobsthal.size() - 2];
    if (next >= static_cast<int>(size))
      break;
    jacobsthal.push_back(next);
  }
  return jacobsthal;
}

// 2, 5, 1, 6, | 7, 3, 8, 4, 9
// void PmergeMe::mergeInsertionSort(std::vector<int> &vector) {
//   // Base case: already sorted if 0 or 1 elements
//   if (vector.size() <= 1)
//     return;
//
//   // Containers for our algorithm
//   std::vector<std::pair<int, int> > pairs;
//   std::vector<int> sorted;
//   size_t odd_check = vector.size() % 2;  // Check if we have odd number of elements
//
//   // Step 1: Create sorted pairs
//   for (size_t i = 0; i < vector.size() - odd_check; i += 2) {
//     if (vector[i] > vector[i + 1])
//       pairs.push_back(std::make_pair(vector[i], vector[i + 1]));
//     else
//       pairs.push_back(std::make_pair(vector[i + 1], vector[i]));
//   }
// // pairs: [5, 2], [6, 1], [7, 3], [8, 4]
//   
//   // Handle odd element if present
//   int odd = -1;
//   if (odd_check)
//     // odd = vector[vector.size() - 1]; // If odd, store last element
//     odd = vector.back();
//
//   // Step 2: Extract larger elements
//   std::vector<int> large;
//   for (size_t i = 0; i < pairs.size(); i++) {
//     large.push_back(pairs[i].first);
//   }
//
//   // Step 3: Recursively sort larger elements
//   mergeInsertionSort(large);
//
//   // Step 4: Initialize sorted with main chain
//   sorted = large;
//   // Step 5: Insert smaller elements using Jacobsthal sequence
//   if (!pairs.empty()) {
//     // Insert first small element
//     std::vector<int>::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), pairs[0].second);
//     sorted.insert(pos, pairs[0].second);
//   }
//   // Generate Jacobsthal numbers
//   std::vector<int> jacobsthal = jacobsthal_number(pairs.size());
//   // Insert remaining elements by Jacobsthal ranges
//   for (size_t j = 1; j < jacobsthal.size(); j++) {
//     for (int i = jacobsthal[j - 1] + 1; i <= jacobsthal[j] && i < static_cast<int>(pairs.size()); i++) {
//       std::vector<int>::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), pairs[i].second);
//       sorted.insert(pos, pairs[i].second);
//     }
//   }
//
//   // Insert any remaining elements not covered by Jacobsthal sequence
//   for (size_t i = jacobsthal.back() + 1; i < pairs.size(); i++) {
//     std::vector<int>::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), pairs[i].second);
//     sorted.insert(pos, pairs[i].second);
//   }
//
//   // Insert odd element if it exists
//   if (odd != -1) {
//     std::vector<int>::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), odd);
//     sorted.insert(pos, odd);
//   }
//   // Update original vector with sorted result
//   vector = sorted;
// }









