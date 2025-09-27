#include <iostream>

enum class Animal
{
    pig,
    chicken,
    goat,
    cat,
    dog,
    duck,
};

constexpr std::string_view getAnimalName(Animal animal)
{
    using enum Animal;

    switch (animal)
    {
    case pig: return "pig";
    case chicken: return "chicken";
    case goat: return "goat";
    case cat: return "cat";
    case dog: return "dog";
    case duck: return "duck";
    default: return "???";
    }
}

void printAnimal(std::string_view animal, int legs)
{
    std::cout << "A " << animal << "has " << legs << " legs\n";
}

void printNumberOfLegs(Animal animal)
{
    using enum Animal;

    switch (animal)
    {
    case pig:
        printAnimal(getAnimalName(pig), 4);
        break;
    case chicken: 
        printAnimal(getAnimalName(chicken), 2);
        break;
    case goat:
        printAnimal(getAnimalName(goat), 4);
        break;
    case cat:
        printAnimal(getAnimalName(cat), 4);
        break;
    case dog:
        printAnimal(getAnimalName(dog), 4);
        break;
    case duck:
        printAnimal(getAnimalName(duck), 2);
        break;
    }
}

int main()
{
    enum class Color
    {
        red,
        blue,
    };

    enum class Fruit
    {
        banana,
        apple,
    };

    printNumberOfLegs(Animal::cat);
    printNumberOfLegs(Animal::chicken);

    return 0;
}