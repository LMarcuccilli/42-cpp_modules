#include "Character.hpp"

#include <string>
#include <iostream>

Character::Character() : _name("default"), _unequippedCount(0)
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = 0;
}

Character::Character(const std::string &name) : _name(name), _unequippedCount(0)
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = 0;
}

Character::Character(Character const &other)
{
	_name = other._name;
	copyInventory(other);
	copyUnequipped(other);
}

Character &Character::operator=(Character const &other)
{
	if (this != &other)
	{
		clearInventory();
		clearUnequipped();
		_name = other._name;
		copyInventory(other);
		copyUnequipped(other);
	}
	return *this;
}

Character::~Character()
{
	clearInventory();
	clearUnequipped();
}

std::string const &Character::getName() const
{
	return _name;
}

void Character::copyInventory(const Character &other)
{
	for (int i = 0; i < 4; i++)
	{
		if (other._inventory[i])
			_inventory[i] = other._inventory[i]->clone();
		else
			_inventory[i] = 0;
	}
}

void Character::copyUnequipped(const Character &other)
{
	for (int i = 0; i < other._unequippedCount; i++)
		_unequipped[i] = other._unequipped[i]->clone();
	_unequippedCount = other._unequippedCount;
}

void Character::clearInventory()
{
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i])
		{
			delete _inventory[i];
			_inventory[i] = 0;
		}
	}
}

void Character::clearUnequipped()
{
	for (int i = 0; i < _unequippedCount; i++)
		delete _unequipped[i];
}

void Character::equip(AMateria *m)
{
	if (!m)
		return;
	for (int i = 0; i < 4; i++)
	{
		if (!_inventory[i])
		{
			std::cout << _name << " equipped " << m->getType() << " at index " << i << std::endl;
			_inventory[i] = m;
			return;
		}

	}
	std::cout << _name << " couldn't equip " << m->getType() << " because inventory is full" << std::endl;

}

void Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
	{
		std::cout << "index " << idx << " is invalid" << std::endl;
		return;
	}
	if (_inventory[idx] && _unequippedCount < MAX_UNEQUIPPED)
	{
		std::cout << _name << " unequipped " << _inventory[idx]->getType() << " at index " << idx << std::endl;
		_unequipped[_unequippedCount] = _inventory[idx];
		_unequippedCount++;
		_inventory[idx] = 0;
	}
	else if (_unequippedCount >= MAX_UNEQUIPPED)
		std::cout << _name << " couldn't unequip because MAX_UNEQUIPPED has been reached" << std::endl;
	else
		std::cout << _name << " couldn't unequip because inventory[" << idx << "] is empty" << std::endl;
}

void Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx > 3)
	{
		std::cout << "index " << idx << " is invalid" << std::endl;
		return ;
	}
	if (_inventory[idx])
	{
		std::cout << _name << " used " << _inventory[idx]->getType() << " on " << target.getName() << std::endl;
		_inventory[idx]->use(target);
	}
	else
		std::cout << _name << " couldn't use inventory[" << idx << "] on " << target.getName() << " because it's empty" << std::endl;
}
