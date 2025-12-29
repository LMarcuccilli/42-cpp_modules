#pragma once

#include "AMateria.hpp"

class Ice : public AMateria {
public:
    Ice();

    Ice(Ice const &other);

    Ice &operator=(Ice const &other);

    ~Ice();

    AMateria *clone() const;

    void use(ICharacter &target);
};
