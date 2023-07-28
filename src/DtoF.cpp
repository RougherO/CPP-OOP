#include <iostream>

int main()
{
    const double PI = 3.14159;
    double radius {};
    std::cout << "Enter radius of circle : ";
    std::cin >> radius;
    std::cout << "Area of circle : " << PI * radius * radius;
}