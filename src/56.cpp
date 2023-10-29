#include <iostream>
#include <cstring>

template<typename T>
const T* Max(const T* entity1, const T* entity2)
{
    return *entity1 < *entity2 ? entity1 : entity2;
}

template<>
const char* Max(const char* entity1, const char* entity2)
{
    return std::strcmp(entity1, entity2) > 0 ? entity1 : entity2;
}

int main()
{
    int num1, num2;

    std::cout << "Enter num1: ";
    std::cin >> num1;
    std::cout << "Enter num2: ";
    std::cin >> num2;

    std::cout << "Max of " << num1 << " and " << num2 << " is: " << *Max(&num1, &num2) << "\n";

    std::string s1, s2;
    std::cout << "Enter string1: ";
    std::cin >> s1;
    std::cout << "Enter string2: ";
    std::cin >> s2;

    std::cout << "Max of " << s1 << " and " << s2 << " is: " << *Max(&s1, &s2) << "\n";
}