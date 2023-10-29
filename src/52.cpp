#include <iostream>

class classWithException {
public:
    class Exception {
        const char* m_description;

    public:
        Exception(const char* description)
            : m_description(description)
        {
        }
        const char* what() const
        {
            return m_description;
        }
    };

    void throwCustomException() noexcept(true)
    {
        throw Exception("Custom exception thrown");
    }
};

int main()
{
    classWithException Obj;

    try {
        Obj.throwCustomException();
    } catch (const classWithException::Exception& ex) {
        std::cout << "Caught custom exception: " << ex.what() << std::endl;
    }

    return 0;
}