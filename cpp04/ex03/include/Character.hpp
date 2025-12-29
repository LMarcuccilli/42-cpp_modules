#pragma once

#include "ICharacter.hpp"

class Character : public ICharacter {
private:
    std::string _name;
    AMateria *_inventory[4];

    void copyInventory(const Character &other);
    void clearInventory() const;

public:
    Character();

    Character(const std::string &name);

    Character(Character const &other);

    Character &operator=(Character const &other);

    ~Character();

    std::string const &getName() const;

    void equip(AMateria *m);

    void unequip(int idx);

    void use(int idx, ICharacter &target);
};
