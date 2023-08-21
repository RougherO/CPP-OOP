#include <iostream>

class Complex {
private:
    double m_real {};
    double m_imag {};

public:
    Complex(double real = 0, double imag = 0)
        : m_real { real }
        , m_imag { imag }
    {
    }

    Complex(const Complex& other) = default;

    Complex& operator=(const Complex& other) = default;

public:
    void setReal(double real)
    {
        m_real = real;
    }

    void setImag(double imag)
    {
        m_imag = imag;
    }

public:
    double getReal() const
    {
        return m_real;
    }

    double getImag() const
    {
        return m_imag;
    }

public:
    void disp()
    {
        std::cout << m_real << " + " << m_imag << "j";
        std::cout << std::endl;
    }

    Complex sum(const Complex& other)
    {
        return Complex(m_real + other.m_real, m_imag + other.m_imag);
    }
};

int main()
{
    Complex c1(1, 1);
    c1.disp();
    Complex c2(2, 3);
    c2.disp();
    Complex c3 = c1.sum(c2);
    c3.disp();
}