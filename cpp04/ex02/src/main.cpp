#include "AAnimal.hpp"
#include "Brain.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    //AAnimal p; // impossible

    Dog *dog = new Dog();

    dog->getBrain().setIdea("bones", 0);
    std::cout << dog->getBrain().getIdea(0) << std::endl;
    delete dog;
    return 0;
}
