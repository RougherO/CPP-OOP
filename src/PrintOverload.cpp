#include <vector>
#include <iostream>

void print(std::vector<int> arr)
{
    for (const int& i : arr) {
        std::cout << i << " ";
    }
    std::cout << "\n";
}

void print(std::vector<std::vector<int>> matrix)
{
    for (const auto& j : matrix) {
        for (const int& i : j) {
            std::cout << i << " ";
        }
        std::cout << "\n";
    }
}
