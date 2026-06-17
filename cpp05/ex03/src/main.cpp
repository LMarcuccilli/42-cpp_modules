#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

int main()
{
	srand(time(0));

	Bureaucrat boss("Boss", 1);
	Bureaucrat mid("Mid", 50);
	Bureaucrat low("Low", 150);

	Intern someRandomIntern;

	AForm *shrub = NULL;
	AForm *robot = NULL;
	AForm *pardon = NULL;
	AForm *unknown = NULL;

	std::cout << "\n========== FORM CREATION TESTS ==========\n\n";

	shrub = someRandomIntern.makeForm("shrubbery creation", "home");
	robot = someRandomIntern.makeForm("robotomy request", "Bender");
	pardon = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");
	unknown = someRandomIntern.makeForm("unknown form", "Nobody");

	std::cout << "\n========== NULL CHECK ==========\n\n";

	if (!shrub)
		std::cout << "shrub creation failed" << std::endl;
	if (!robot)
		std::cout << "robot creation failed" << std::endl;
	if (!pardon)
		std::cout << "pardon creation failed" << std::endl;
	if (!unknown)
		std::cout << "unknown form correctly returned NULL" << std::endl;

	std::cout << "\n========== SIGNING TESTS ==========\n\n";

	if (shrub)
	{
		low.signForm(*shrub);
		mid.signForm(*shrub);
	}

	if (robot)
	{
		low.signForm(*robot);
		mid.signForm(*robot);
	}

	if (pardon)
	{
		mid.signForm(*pardon);
		boss.signForm(*pardon);
	}

	std::cout << "\n========== EXECUTION TESTS ==========\n\n";

	if (shrub)
	{
		low.executeForm(*shrub);
		mid.executeForm(*shrub);
	}

	if (robot)
	{
		mid.executeForm(*robot);
		boss.executeForm(*robot);
		boss.executeForm(*robot);
		boss.executeForm(*robot);
	}

	if (pardon)
	{
		mid.executeForm(*pardon);
		boss.executeForm(*pardon);
	}

	std::cout << "\n========== UNSIGNED FORM TEST ==========\n\n";

	AForm *unsignedRobot = someRandomIntern.makeForm("robotomy request", "UnsignedBot");

	if (unsignedRobot)
		boss.executeForm(*unsignedRobot);

	std::cout << "\n========== CLEANUP ==========\n\n";

	delete shrub;
	delete robot;
	delete pardon;
	delete unknown;
	delete unsignedRobot;

	std::cout << "All allocated forms deleted." << std::endl;

	std::cout << "\n========== DONE ==========\n";

	return 0;
}
