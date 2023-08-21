#include <iostream>

class INT {
    int i;

public:
    INT(int a)
        : i(a)
    {
    }
    ~INT() {}

    INT& operator++()
    {
        ++i;
        return *this;
    }

    INT operator++(int)
    {
        INT temp { *this };
        ++i;
        return temp;
    }

    operator int()
    {
        return i;
    }
};

int main()
{
    int x = 3;
    INT y = x;
    y++ = ++y; // default copy assignment operator provided by compiler
    x = y;
    return 0;
}