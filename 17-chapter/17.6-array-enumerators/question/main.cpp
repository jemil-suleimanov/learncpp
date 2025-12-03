#include <iostream>
#include <string_view>

namespace Animal
{
    enum Type
    {
        chicken,
        dog,
        cat,
        elephant,
        duck,
        snake,
        max_animals
    };

    struct Data
    {
        std::string_view name{};
        int legs{};
        std::string_view sound{};
    };

    std::array<Data, max_animals> animals {{
        { "chicken", 2, "cluck"},
        { "dog", 4, "woof"},
        { "cat", 4, "meow"},
        { "elephant", 4, "pawoo"},
        { "duck", 2, "quack"},
        { "snake", 0, "hissss"},
    }};

    static_assert(std::size(animals) == max_animals);
};

Animal::Data getAnimal(Animal::Type animal)
{
    return Animal::animals[static_cast<size_t>(animal)];
}

std::ostream& operator<<(std::ostream& out, Animal::Type animal)
{
    auto anim { getAnimal(animal) };
    return out << "A " << anim.name << " has " << anim.legs << " legs and says " << anim.sound << ".\n";
}

std::istream& operator>> (std::istream& in, Animal::Type& animal)
{
    std::string input{};
    std::getline(in >> std::ws, input);

    for (std::size_t index=0; index < Animal::animals.size(); index++)
    {
        if (input == Animal::animals[index].name)
        {
            animal = static_cast<Animal::Type>(index);
            return in;
        }
    }

    in.setstate(std::ios_base::failbit);

    return in;
}

void printAnimalsExcept(Animal::Type animal)
{
    std::cout << "\nHere is the data for the rest of the animals:\n";
    for (std::size_t index=0; index < Animal::animals.size(); index++)
    {
        if (static_cast<Animal::Type>(index) != static_cast<std::size_t>(animal))
        {
            std::cout << static_cast<Animal::Type>(index);
        }
    }
}

int main()
{
    Animal::Type animal {};

    std::cout << "Enter an animal: ";
    std::cin >> animal;
    if (!std::cin)
        std::cout << "That animal couldn't be found.\n";
    else
        std::cout << animal;
    
    printAnimalsExcept(animal);

    return 0;
}
