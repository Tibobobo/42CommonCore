#include "Cat.hpp"
#include "Dog.hpp"

int main(void) {

    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    const WrongAnimal *test = new WrongCat();

    std::cout << meta->getType() << " " << std::endl;
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    std::cout << test->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound even though i is a pointer on Animal, thanks to "virtual" keyword that allows for dynamic linking
    j->makeSound();
    meta->makeSound(); // will output default animal sound, because meta is just an Animal
    test->makeSound(); // will output default animal sound, because without "virtual" keyword, linking is static and therefore the pointer's type is used to choose the function
    delete meta;
    delete j;
    delete i;
    delete test;
    return (0);
}