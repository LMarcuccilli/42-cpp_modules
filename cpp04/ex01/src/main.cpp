#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#define NB 10

// int main()
// {
//     Animal* a[NB];
//     for (int i = 0; i < NB; i++)
//     {
//         if (i < NB / 2)
//             a[i] = new Dog;
//         else
//             a[i] = new Cat;
//     }

//     for (int i = 0; i < NB; i++)
//     {
//         delete a[i];
//     }
// }

int main()
{
    Dog dog;
    dog.getBrain().setIdea("bone", 0);

    Dog dog2 = dog;
    dog.getBrain().setIdea("sausage", 0);

    dog2 = dog;
    std::cout << dog.getBrain().getIdea(0) << std::endl;
    std::cout << dog2.getBrain().getIdea(0) << std::endl;
}