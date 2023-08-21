#include <iostream>
#include <algorithm>

class IntArray {

private:
    const static size_t m_buffer { 15 };
    size_t m_capacity {};
    size_t m_size {};
    int* m_arr {};

public:
    IntArray()
        : m_capacity { m_buffer }
        , m_arr { new int[m_capacity] {} }
    {
    }

    IntArray(size_t size)
        : m_capacity { size / m_buffer * m_buffer + m_buffer }
        , m_size { size }
        , m_arr { new int[m_capacity] {} }
    {
    }

    IntArray(size_t size, const int value)
        : m_capacity { size / m_buffer * m_buffer + m_buffer }
        , m_size { size }
        , m_arr { new int[m_capacity] {} }
    {
        for (size_t i = 0; i < m_size; ++i) {
            m_arr[i] = value;
        }
    }

    IntArray(const IntArray& arr)
        : m_capacity { arr.m_capacity }
        , m_size { arr.m_size }
        , m_arr { new int[m_capacity] {} }
    {
        for (int i = 0; i < m_size; ++i) {
            m_arr[i] = arr.m_arr[i];
        }
    }

    ~IntArray()
    {
        delete[] m_arr;
    }

public:
    void set(size_t index, int val)
    {
        if (index >= m_size || index < 0) {
            // throw error
        }
        m_arr[index] = val;
    }

    int at(size_t index) const
    {
        if (index >= m_size || index < 0) {
            // throw error
        }
        return m_arr[index];
    }

    size_t length() const
    {
        return m_size;
    }

    void push_back(const int value)
    {

        if (m_size < m_capacity) {
            m_arr[m_size] = value;
            m_size += 1;
            return;
        }

        if (m_size == m_capacity) {
            m_capacity <<= 1;
            int* temp = m_arr;
            m_arr = new int[m_capacity] {};
            for (int i = 0; i < m_size; ++i) {
                m_arr[i] = temp[i];
            }
            m_arr[m_size] = value;
            delete[] temp;
        }

        m_size += 1;
        return;
    }

    void pop_back()
    {
        if (m_size) {
            m_size -= 1;
        } else {
            // throw error
        }
    }

    void reverse()
    {
        std::reverse(m_arr, m_arr + m_size);
    }

    void sort()
    {
        std::sort(m_arr, m_arr + m_size);
    }

    void print()
    {
        for (int i = 0; i < m_size; ++i) {
            std::cout << m_arr[i] << " ";
        }
        std::cout << "\n";
    }

    void add(const IntArray& arr)
    {
        m_capacity += arr.m_capacity;
        m_size += arr.m_size;
        int* temp = new int[m_capacity] {};
        for (int i = 0; i < m_size; ++i) {
            temp[i] = m_arr[i];
        }
        for (int i = 0; i < arr.m_size; ++i) {
            temp[m_size + i] = arr.m_arr[i];
        }
        delete[] m_arr;
        m_arr = temp;
    }
};

int main()
{
    IntArray arr(3);
    for (int i = 0; i < 3; ++i) {
        arr.set(i, i + 1);
    }
    arr.print();
    IntArray arr1(arr);
    arr1.print();
    arr1.reverse();
    arr1.print();
}