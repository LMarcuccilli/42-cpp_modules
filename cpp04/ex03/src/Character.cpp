#include "Character.hpp"

#include <string>

Character::Character() : _name("default") {
    for (int i = 0; i < 4; i++)
        _inventory[i] = 0;
}

Character::Character(const std::string &name) : _name(name) {
    for (int i = 0; i < 4; i++)
        _inventory[i] = 0;
}

Character::Character(Character const &other) {
    _name = other._name;
    copyInventory(other);
}

Character &Character::operator=(Character const &other) {
    if (this != &other) {
        clearInventory();
        _name = other._name;
        copyInventory(other);
    }
    return *this;
}

Character::~Character() {
    clearInventory();
}

std::string const &Character::getName() const {
    return _name;
}

void Character::copyInventory(const Character &other) {
    for (int i = 0; i < 4; i++) {
        if (other._inventory[i])
            _inventory[i] = other._inventory[i]->clone();
        else
            _inventory[i] = 0;
    }
}

void Character::clearInventory() {
    for (int i = 0; i < 4; i++) {
        if (_inventory[i]) {
            delete _inventory[i];
            _inventory[i] = 0;
        }
    }
}

void Character::equip(AMateria *m) {
    if (!m)
        return ;
    for (int i = 0; i < 4; i++) {
        if (!_inventory[i]) {
            _inventory[i] = m;
            return ;
        }
    }
}

void Character::unequip(int idx) {
    if (idx < 0 || idx > 3)
        return ;
    _inventory[idx] = 0;
}

void Character::use(int idx, ICharacter &target) {
    if (idx < 0 || idx > 3)
        return ;
    if (_inventory[idx])
        _inventory[idx]->use(target);
}
