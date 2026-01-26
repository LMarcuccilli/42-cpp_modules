#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    // Wrong
    const WrongAnimal* meta = new WrongAnimal();
    const WrongAnimal* i = new WrongCat();
    std::cout << i->getType() << std::endl;
    i->makeSound();
    meta->makeSound();
    delete meta;
    delete i;


    // Right
    // const Animal* beta = new Animal();
    // const Animal* j = new Dog();
    // std::cout << j->getType() << std::endl;
    // j->makeSound();
    // beta->makeSound();

    // delete beta;
    // delete j;
    return 0;
}
