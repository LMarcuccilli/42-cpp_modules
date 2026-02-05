#include "../include/ScalarConverter.hpp"
#include <string>

int main(int ac, char *av[])
{
	(void)ac;
	for (int i = 1; av[i]; i++)
	{
		std::string arg(av[i]);
		ScalarConverter::convert(arg);
	}

	return 0 ;
}

