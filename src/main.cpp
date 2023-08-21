#include <iostream>
#include <cmath>

class Complex {
private:
    double m_real {};
    double m_imag {};

public:
    Complex(double real, double imag)
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
    friend std::ostream& operator<<(std::ostream& os, const Complex& num)
    {
        return std::cout << num.m_real << " + " << num.m_imag << "j";
    }

    Complex operator+(const Complex& other)
    {
        return Complex(m_real + other.m_real, m_imag + other.m_imag);
    }

    Complex& operator+=(const Complex& other)
    {
        *this = *this + other;
        return *this;
    }

    Complex operator-(const Complex& other)
    {
        return Complex(m_real - other.m_real, m_imag - other.m_imag);
    }

    Complex& operator-=(const Complex& other)
    {
        *this = *this - other;
        return *this;
    }

    Complex operator*(const Complex& other)
    {
        return Complex(m_real * other.m_real - m_imag * other.m_imag, m_real * other.m_imag + m_imag * other.m_real);
    }

    Complex& operator*=(const Complex& other)
    {
        *this = *this * other;
        return *this;
    }

    Complex operator/(const Complex& other)
    {
        double denom = std::pow(other.m_real, 2) + std::pow(other.m_imag, 2);
        return Complex(
            (m_real * other.m_real + m_imag * other.m_imag) / denom,
            (m_imag * other.m_real - m_real * other.m_imag) / denom);
    }

    Complex& operator/=(const Complex& other)
    {
        *this = *this / other;
        return *this;
    }
};

int main()
{
}
