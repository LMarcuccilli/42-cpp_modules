#include "Animal.hpp"
#include "Brain.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#define NB 10

int main(void)
{
	Animal *a[NB];
	(void)a;
	for (int i = 0; i < NB; i++)
	{
		if (i < NB / 2)
			a[i] = new Dog();
		else
			a[i] = new Cat();
	}
	for (int i = 0; i < NB; i++)
		a[i]->makeSound();
	for (int i = 0; i < NB; i++)
		delete a[i];

	Cat catA;
	Cat catB;
	catA.getBrain().setIdea("fiiish", 0);
	catB = catA;

	std::cout << catB.getBrain().getIdea(0) << std::endl;

	return 0;
}
