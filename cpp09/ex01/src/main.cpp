#include <iostream>

int main(int ac, char *av[]) {
	if (ac < 2) {
		std::cerr << "Error: 1 argument required" << std::endl;
		return 1;
	}

	std::cout << av[1] << std::endl;
	return 0;
}
