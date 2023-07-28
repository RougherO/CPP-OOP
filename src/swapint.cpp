#include <iostream>

void swap(int& x, int& y)
{
    int z = y;
    y = x;
    x = z;
}

int main()
{
    int x { 1 }, y { 2 };
    std::cout << "Before Swap : " << x << " " << y << "\n";
    swap(x, y);
    std::cout << "After Swap : " << x << " " << y << "\n";
}