#include <iostream>

int main()
{
    int numerator, denominator;

    std::cout << "Enter the numerator: ";
    std::cin >> numerator;

    std::cout << "Enter the denominator: ";
    std::cin >> denominator;

    try {
        if (denominator == 0) {
            throw "Division by zero is not allowed.";
        }

        int result = numerator / denominator;
        std::cout << "Result of division: " << result << std::endl;
    } catch (const char* errorMessage) {
        std::cout << "Exception caught: " << errorMessage << std::endl;
    }

    return 0;
}