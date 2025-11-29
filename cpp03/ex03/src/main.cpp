#include "ClapTrap.hpp"
#include "DiamondTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main()
{
    std::cout << "=== Creating ClapTrap ===" << std::endl;
    ClapTrap ct1("CT-One");
    ct1.attack("Target-A");
    ct1.takeDamage(3);
    ct1.beRepaired(5);

    std::cout << "\n=== Creating ScavTrap ===" << std::endl;
    ScavTrap st1("ST-One");
    st1.attack("Target-B");
    st1.takeDamage(10);
    st1.beRepaired(8);
    st1.guardGate();

    std::cout << "\n=== Creating FragTrap ===" << std::endl;
    FragTrap ft1("FT-One");
    ft1.attack("Target-C");
    ft1.takeDamage(20);
    ft1.beRepaired(15);
    ft1.highFivesGuys();

    std::cout << "\n=== Creating DiamondTrap ===" << std::endl;
    DiamondTrap dt1("DT-One");
    dt1.attack("Target-D");          // Should use ScavTrap::attack
    dt1.takeDamage(25);              // Uses ClapTrap::takeDamage
    dt1.beRepaired(10);              // Uses ClapTrap::beRepaired
    dt1.whoAmI();                     // DiamondTrap-specific
    dt1.guardGate();                  // From ScavTrap
    dt1.highFivesGuys();              // From FragTrap

    std::cout << "\n=== Testing copy constructor ===" << std::endl;
    DiamondTrap dt2(dt1);
    dt2.whoAmI();

    std::cout << "\n=== Testing assignment operator ===" << std::endl;
    DiamondTrap dt3;
    dt3 = dt1;
    dt3.whoAmI();

    std::cout << "\n=== End of tests ===" << std::endl;

    return 0;
}
