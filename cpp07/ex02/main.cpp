#include "Array.hpp"




int main() {
  try {
    std::cout << "Test 1: Default constructor" << std::endl;
    Array<int> A;
    std::cout << "Size: " << A.size() << std::endl;

    std::cout << "\nTest 2: Constructor with size" << std::endl;
    Array<int> B(5);
    std::cout << "Size: " << B.size() << std::endl;
    for (unsigned int i = 0; i < B.size(); ++i)
      std::cout << "B[" << i << "] = " << B[i] << std::endl;

    std::cout << "\nTest 3: Copy constructor" << std::endl;
    Array<int> C(B);
    C[0] = 100;
    std::cout << "B[0]: " << B[0] << ", C[0]: " << C[0] << std::endl;

    std::cout << "\nTest 4: Assignment operator" << std::endl;
    Array<int> D;
    D = B;
    D[1] = 200;
    std::cout << "B[1]: " << B[1] << ", D[1]: " << D[1] << std::endl;

    std::cout << "\nTest 5: Bounds checking" << std::endl;
    std::cout << "B[10]..." << std::endl;
    std::cout << B[10] << std::endl;
  }
  catch (std::exception& e) {
    std::cerr << "Exception caught: " << e.what() << std::endl;
  }

  return 0;
}

/* #include <cstdlib>
#include <ctime>
#define MAX_VAL 750
int main(int, char**)
{
  Array<int> numbers(MAX_VAL);
  int* mirror = new int[MAX_VAL];
  srand((unsigned int)time(NULL));
  for (int i = 0; i < MAX_VAL; i++)
  {
    const int value = rand();
    numbers[i] = value;
    mirror[i] = value;
  }
  //SCOPE
  {
    Array<int> tmp = numbers;
    Array<int> test(tmp);
  }

  for (int i = 0; i < MAX_VAL; i++)
  {
    if (mirror[i] != numbers[i])
    {
      std::cerr << "didn't save the same value!!" << std::endl;
      return 1;
    }
  }
  try
  {
    numbers[-2] = 0;
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
  }
  try
  {
    numbers[MAX_VAL] = 0;
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
  }

  for (int i = 0; i < MAX_VAL; i++)
  {
    numbers[i] = rand();
  }
  delete [] mirror;//
  return 0;
} */

