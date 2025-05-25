#include "iter.hpp"

int main()
{
	std::string arr[] = {"hello", "world", "Welcome"};
	iter(arr, 3, printElement<std::string>);

	int	arr2[] = {10, 20, 30, 40};
	iter(arr2, 4, sqrt<int>);
	iter(arr2, 4, printElement<int>);
}


