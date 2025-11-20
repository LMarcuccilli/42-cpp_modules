#include "ScavTrap.hpp"

int main() {
    std::cout << "\n--- Default ScavTrap ---\n";
    ScavTrap st_default;
    st_default.attack("TargetDummy");
    st_default.takeDamage(20);
    st_default.beRepaired(15);
    st_default.guardGate();

    std::cout << "\n--- Named ScavTrap ---\n";
    ScavTrap st("GateKeeper");
    st.attack("Intruder");
    st.takeDamage(90);
    st.beRepaired(30);
    st.guardGate();

    std::cout << "\n--- Copy constructor ---\n";
    ScavTrap st_copy(st);
    st_copy.attack("CloneTarget");
    st_copy.guardGate();

    std::cout << "\n--- Assignment operator ---\n";
    ScavTrap st_assign;
    st_assign = st_default;
    st_assign.attack("AssignedTarget");
    st_assign.guardGate();

    std::cout << "\n--- Exhausting energy ---\n";
    ScavTrap st_energy("LowBattery");
    for (int i = 0; i < 55; i++) {
        st_energy.attack("SpamTarget");
    }

    std::cout << "\n--- Done ---\n";
    return 0;
}
