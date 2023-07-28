#include <iostream>

int factorial(const int& num)
{
    int result = 1;
    for (int i = 1; i <= num; ++i) {
        result *= i;
    }
    return result;
}

int main()
{
    int num {};
    std::cout << "Enter number to compute : ";
    std::cin >> num;
    std::cout << "Factorial of " << num << " : " << factorial(num) << "\n";
}