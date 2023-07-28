#include <iostream>

int main()
{
    for (int i { 1 }, j { 1 }; i < 7; ++i, j *= i) {
        std::cout << i << "! = " << j << "\n";
    }
}