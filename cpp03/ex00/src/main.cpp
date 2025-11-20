#include "ClapTrap.hpp"

int main() {
    // ► Test default constructor
    ClapTrap robot1;

    // ► Test constructor with name
    ClapTrap robot2("Bob");

    // ► Test copy constructor
    ClapTrap robot3(robot2);

    // ► Test assignment operator
    ClapTrap robot4;
    robot4 = robot1;

    // ► Test attack
    robot1.attack("Target A");
    robot2.attack("Target B");

    // ► Test takeDamage
    robot1.takeDamage(5);
    robot2.takeDamage(15);  // test going below 0

    // ► Test beRepaired
    robot1.beRepaired(3);
    robot2.beRepaired(10);  // test repair after HP went to 0

    // ► Test energy points depletion
    for (int i = 0; i < 12; ++i)
        robot1.attack("Dummy");

    return 0;
}
