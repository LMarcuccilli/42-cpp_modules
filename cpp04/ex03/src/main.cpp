#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

#include <iostream>

int main()
{
    MateriaSource src;
    Ice *ice = new Ice();
    Cure *cure = new Cure();

    src.learnMateria(ice);
    src.learnMateria(cure);

    delete ice;
    delete cure;

    Character me("me");

    AMateria* tmp;
    tmp = src.createMateria("ice");
    me.equip(tmp);
    tmp = src.createMateria("cure");
    me.equip(tmp);

    Character bob("Bob");
    me.use(0, bob);
    me.use(1, bob);

    me.unequip(1);
}

// int main(void)
// {
//     Character c("patrick");
//     for (int i = 0; i < 100; i++)
//     {
//         c.equip(new Cure());
//         c.unequip(0);
//     }
//     Character copy = c;
//     return 0;
// }
