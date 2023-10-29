#include <exception>
#include <iostream>

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
    Stack(std::size_t);

    const T& top() const;
    void push(T);
    T pop();

    template<typename U> friend std::ostream& operator<<(std::ostream& os, const Stack<U>& st);

    ~Stack();
};

template<typename T>
Stack<T>::Stack(std::size_t sz)
    : buffer { new T[sz] {} }
    , max_size { sz }
    , size {}
{
}

template<typename T>
const T& Stack<T>::top() const
{
    return buffer[size - 1];
}

template<typename T>
void Stack<T>::push(T data)
{
    if (size == max_size) {
        throw stackOverflowException();
    }
    buffer[size++] = data;
}

template<typename T>
T Stack<T>::pop()
{
    if (size == 0) {
        throw stackUnderflowException();
    }
    return buffer[size--];
}

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

template<typename T>
Stack<T>::~Stack()
{
    delete[] buffer;
}

int main()
{
    Stack<int> st(5);
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    /* st.push(6);
     * Stack Overflow
     */
    st.pop();
    st.pop();
    std::cout << st << std::endl;
}