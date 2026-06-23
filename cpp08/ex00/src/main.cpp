#include "easyfind.hpp"
#include <cstdlib>
#include <iostream>
#include <vector>

int main(int argc, char const *argv[]) {
  if (argc < 2) {
	std::cout << "Usage: ./program numbers..." << std::endl;
	return 1;
  }
  std::vector<int> arr;
  for (int i = 1; i < argc; i++) {
	arr.push_back(std::atoi(argv[i]));
  }

  std::cout << ::easyfind(arr, std::atoi(argv[1])) << std::endl;

  return 0;
}
