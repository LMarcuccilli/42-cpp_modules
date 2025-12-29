#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

#include <iostream>

int main()
{
    std::cout << "=== Creating MateriaSource ===" << std::endl;
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    std::cout << "\n=== Creating Character ===" << std::endl;
    ICharacter* me = new Character("me");

    AMateria* tmp;

    std::cout << "\n=== Creating and equipping Materias ===" << std::endl;
    tmp = src->createMateria("ice");
    me->equip(tmp);

    tmp = src->createMateria("cure");
    me->equip(tmp);

    std::cout << "\n=== Creating target Character ===" << std::endl;
    ICharacter* bob = new Character("bob");

    std::cout << "\n=== Using materias ===" << std::endl;
    me->use(0, *bob);
    me->use(1, *bob);

    std::cout << "\n=== Unequip test (no delete) ===" << std::endl;
    me->unequip(0);
    me->use(0, *bob); // should do nothing
    me->use(1, *bob); // still works

    std::cout << "\n=== Copy constructor test ===" << std::endl;
    Character copy(*(Character*)me);
    copy.use(1, *bob);

    std::cout << "\n=== Assignment operator test ===" << std::endl;
    Character assign;
    assign = *(Character*)me;
    assign.use(1, *bob);

    std::cout << "\n=== Cleanup ===" << std::endl;
    delete bob;
    delete me;
    delete src;

    std::cout << "\n=== End of program ===" << std::endl;
    return 0;
}
