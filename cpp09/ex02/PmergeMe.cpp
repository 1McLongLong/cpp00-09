#include "PmergeMe.hpp"


PmergeMe::PmergeMe(int argc, char **argv) {
  for (int i = 1; i < argc; i++) {
    for (int j = 0; argv[i][j]; j++) {
      if (!std::isdigit(argv[i][j]))
        throw std::runtime_error("Error: invalid argument");
    }
    int num = std::atoi(argv[i]);
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

std::vector<int> PmergeMe::jacobsthalSequence(size_t size) {
  std::vector<int> jacobsthal;
  jacobsthal.push_back(0);
  jacobsthal.push_back(1);
  while (1) {
    int lastN = jacobsthal[jacobsthal.size() - 1];
    int secondLastN = jacobsthal[jacobsthal.size() - 2];
    int next = lastN + 2 * secondLastN;
    if (next >= static_cast<int>(size))
      break;
    jacobsthal.push_back(next);
  }
  return jacobsthal;
}



