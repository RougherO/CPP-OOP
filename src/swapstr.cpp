#include <iostream>

void swapPtr(char** s1, char** s2)
{
    char* t = *s1;
    *s1 = *s2;
    *s2 = t;
}

void swapRef(char*& s1, char*& s2)
{
    char* t = s1;
    s1 = s2;
    s2 = t;
}

int main()
{
    char *str1 = "Hello", *str2 = "World";
    std::cout << "Before Swap : " << str1 << " " << str2 << "\n";
    swapPtr(&str1, &str2);
    std::cout << "After Swap : " << str1 << " " << str2 << "\n";
}