#pragma once
#include "Brain.hpp"
#include "Animal.hpp"

class Cat : public Animal
{
private:
	Brain *_brain;

public:
	Cat();
	Cat(const Cat &other);
	Cat &operator=(const Cat &other);
	~Cat();

	void makeSound(void) const;
	Brain &getBrain(void) const;
};
