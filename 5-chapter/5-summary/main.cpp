#include <iostream>
#include <string>


std::string getName(int personNum)
{
    std::cout << "Enter the name of person #" << personNum << ": ";
    std::string name {};
    std::getline(std:: cin >> std::ws, name);
    return name;
}

int getAge(std::string_view name)
{
    std::cout << "Enter the age of " << name << ": ";
    int age {};
    std::cin >> age;
    return age;
}

void printPerson(std::string_view personName, int personAge)
{
    std::cout << personName <<  " (age " << personAge << ")";
}

void printResult(std::string_view olderPersonName, int olderPersonAge, std::string_view youngerPersonName, int youngerPersonAge)
{
    printPerson(olderPersonName, olderPersonAge);
    std::cout << " is older than ";
    printPerson(youngerPersonName, youngerPersonAge);
    std::cout << '\n';
}

int main()
{
    const std::string firstPersonName { getName(1) };
    const int firstPersonAge { getAge(firstPersonName) };

    const std::string secondPersonName { getName(2) };
    const int secondPersonAge { getAge(secondPersonName) };

    if (firstPersonAge > secondPersonAge)
        printResult(firstPersonName, firstPersonAge, secondPersonName, secondPersonAge);
    else
        printResult(secondPersonName, secondPersonAge, firstPersonName, firstPersonAge);

    return 0;
}
