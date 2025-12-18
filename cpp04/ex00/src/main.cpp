#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    std::cout << "\n=== Correct Animal Tests ===\n";
    const Animal *animal = new Animal();
    const Animal *dog = new Dog();
    const Animal *cat = new Cat();

    std::cout << dog->getType() << std::endl;
    std::cout << cat->getType() << std::endl;

    dog->makeSound(); // Woof
    cat->makeSound(); // Meow
    animal->makeSound();

    delete animal;
    delete dog;
    delete cat;

    std::cout << "\n=== WrongAnimal Tests ===\n";
    const WrongAnimal *wrong = new WrongAnimal();
    const WrongAnimal *wrongcat = new WrongCat();

    std::cout << wrongcat->getType() << std::endl;

    wrong->makeSound();    // WrongAnimal
    wrongcat->makeSound(); // WRONG: still WrongAnimal sound (because not virtual)

    delete wrong;
    delete wrongcat;

    std::cout << "\n=== WrongCat Direct Test ===\n";
    WrongCat directWrongCat;
    directWrongCat.makeSound(); // This prints WrongCat sound (normal override)

    return 0;
}
