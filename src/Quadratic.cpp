#include <iostream>
#include <cmath>
#include <utility>

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

struct Quadratic {

    double a {}, b {}, c {};

    Quadratic(double a = 0, double b = 0, double c = 0)
        : a { a }
        , b { b }
        , c { c }
    {
    }

    Quadratic operator+(const Quadratic& other)
    {
        return Quadratic(a + other.a, b + other.b, c + other.c);
    }

    Quadratic& operator+=(const Quadratic& other)
    {
        a += other.a;
        b += other.b;
        c += other.c;
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const Quadratic& other)
    {
        return os << other.a << "x^2 + " << other.b << "x + " << other.c;
    }

    friend std::istream& operator>>(std::istream& is, Quadratic& other)
    {
        return is >> other.a >> other.b >> other.c;
    }

    double evaluate(double value) const
    {
        return std::pow(value, 2) * a + value * b + c;
    }

    std::pair<Complex, Complex> getRoots() const
    {
        Complex root1 { 0, 0 }, root2 { 0, 0 };
        double disc = b * b - 4 * a * c;
        if (disc > 0) {
            root1 = Complex((-b + std::sqrt(disc)) / (2 * a), 0);
            root2 = Complex((-b - std::sqrt(disc)) / (2 * a), 0);
        } else {
            root1 = Complex(-b / (2 * a), std::sqrt(disc) / (2 * a));
            root2 = Complex(-b / (2 * a), -std::sqrt(disc) / (2 * a));
        }
        return { root1, root2 };
    }
};