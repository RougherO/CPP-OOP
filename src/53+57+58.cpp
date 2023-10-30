#include <iostream>
#include <exception>

template<typename T>
class Stack {
    T* buffer;
    std::size_t max_size, size;

    class stackOverflowException : public std::exception {
        const char* message { "Stack Overflow!" };

    public:
        const char* what() const noexcept override
        {
            return message;
        }
    };

    class stackUnderflowException : public std::exception {
        const char* message { "Stack Underflow!" };

    public:
        const char* what() const noexcept override
        {
            return message;
        }
    };

public:
    Stack(size_t sz)
        : buffer { new T[sz] {} }
        , max_size { sz }
        , size {}
    {
    }

    Stack(const Stack<T>& other)
        : buffer { new T[other.max_size] {} }
        , max_size { other.max_size }
        , size { other.size }
    {
        for (size_t i {}; i < size; ++i) {
            buffer[i] = other.buffer[i];
        }
    }

    Stack<T>& operator=(const Stack<T>& other)
    {
        if (this == &other) {
            return *this;
        }
        max_size = other.max_size;
        size = other.size;

        delete[] buffer;
        buffer = new T[other.max_size];
        for (size_t i {}; i < size; ++i) {
            buffer[i] = other.buffer[i];
        }

        return *this;
    }

    const T& top() const
    {
        return buffer[size - 1];
    }

    void push(T data)
    {
        if (size == max_size) {
            throw stackOverflowException();
        }
        buffer[size++] = data;
    }

    T pop()
    {
        if (size == 0) {
            throw stackUnderflowException();
        }
        return buffer[size--];
    }

    template<typename U> friend std::ostream& operator<<(std::ostream& os, const Stack<U>& st);
    template<typename U> friend void Swap(Stack<U>& st1, Stack<U>& st2);

    ~Stack()
    {
        delete[] buffer;
    }
};

template<typename T>
std::ostream& operator<<(std::ostream& os, const Stack<T>& st)
{
    if (st.size > 0) {
        for (size_t i = st.size - 1; i > 0; --i) {
            os << st.buffer[i] << " ";
        }
        os << st.buffer[0];
    } else {
        os << "Stack Empty!";
    }
    return os;
}

/*
 * This version of Swap requires class to implement move
 * constructors and move assignment operators
 *
 * This is the preferred version since c++11
 */

/*
    template<typename T>
    void Swap(T& entity1, T& entity2)
    {
        T temp { std::move(entity1) };
        entity1 = std::move(entity2);
        entity2 = std::move(temp);
    }
*/

/*
 * This version of swap uses expensive copy constructors
 * and copy assignment operators
 *
 * Used pre c++11
 */
template<typename T>
void Swap(T& entity1, T& entity2)
{
    T temp { entity1 };
    entity1 = entity2;
    entity2 = temp;
}

template<typename T>
void Swap(Stack<T>& st1, Stack<T>& st2)
{
    Swap<size_t>(st1.max_size, st2.max_size);
    Swap<size_t>(st1.size, st2.size);
    Swap<T*>(st1.buffer, st2.buffer);
}

int main()
{
    int num1, num2;

    std::cout << "Enter two numbers: ";
    std::cin >> num1 >> num2;

    std::cout << "Before swap: " << num1 << ", " << num2 << "\n";
    Swap<int>(num1, num2);
    std::cout << "After swap: " << num1 << ", " << num2 << "\n";

    Stack<int> st1 { 5 }, st2 { 5 };

    st1.push(1);
    st1.push(2);
    st1.push(3);

    st2.push(3);
    st2.push(2);
    st2.push(1);

    std::cout << "Before swap: " << st1 << ", " << st2 << "\n";
    Swap<int>(st1, st2);
    std::cout << "After swap: " << st1 << ", " << st2 << "\n";
}