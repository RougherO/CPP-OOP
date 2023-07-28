#include <iostream>

inline int add(int num1, int num2 = 0, int num3 = 0)
{
    return num1 + num3 + num3;
}

int main()
{
    std::cout << "One Paramenter : " << add(1);
    std::cout << "Two Paramenters : " << add(1, 1);
    std::cout << "Three Paramenters : " << add(1, 1, 1);
}