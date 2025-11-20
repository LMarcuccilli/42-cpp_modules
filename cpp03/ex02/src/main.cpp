#include "FragTrap.hpp"

int main() {
    std::cout << "\n--- Default FragTrap ---\n";
    FragTrap fg_default;
    fg_default.attack("TargetDummy");
    fg_default.takeDamage(20);
    fg_default.beRepaired(15);
    fg_default.highFivesGuys();

    std::cout << "\n--- Named FragTrap ---\n";
    FragTrap fg("Fragger");
    fg.attack("Intruder");
    fg.takeDamage(90);
    fg.beRepaired(30);
    fg.highFivesGuys();

    std::cout << "\n--- Copy constructor ---\n";
    FragTrap fg_copy(fg);
    fg_copy.attack("CloneTarget");
    fg_copy.highFivesGuys();

    std::cout << "\n--- Assignment operator ---\n";
    FragTrap fg_assign;
    fg_assign = fg_default;
    fg_assign.attack("AssignedTarget");
    fg_assign.highFivesGuys();

    std::cout << "\n--- Exhausting energy ---\n";
    FragTrap fg_energy("LowBattery");
    for (int i = 0; i < 104; i++) {
        fg_energy.attack("SpamTarget");
    }

    std::cout << "\n--- Done ---\n";
    return 0;
}
