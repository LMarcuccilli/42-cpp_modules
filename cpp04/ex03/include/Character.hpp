#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

#define MAX_UNEQUIPPED 100

class Character : public ICharacter
{
private:
    std::string _name;
    AMateria* _inventory[4];
    AMateria* _unequipped[MAX_UNEQUIPPED];
    int _unequippedCount;

    void copyInventory(const Character& other);
    void clearInventory();
    void copyUnequipped(const Character& other);
    void clearUnequipped();

public:
    Character();

    Character(const std::string& name);

    Character(Character const& other);

    Character& operator=(Character const& other);

    ~Character();

    std::string const& getName() const;

    void equip(AMateria* m);

    void unequip(int idx);

    void use(int idx, ICharacter& target);
};

#endif
