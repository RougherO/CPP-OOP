#include <iostream>

class Person {
    char* m_name;

public:
    Person(int size, char const* name)
        : m_name { new char[size] }
    {
        for (int i {}; i < size; ++i) {
            m_name[i] = name[i];
        }
    }
    ~Person()
    {
        std::cout << "Person destr. called" << std::endl;
        delete[] m_name;
    }
};

class Employee : public Person {
    int m_empID {};
    char* m_deptName {};

public:
    Employee(int size_name, const char* name, int empID, int size_deptName, const char* deptName)
        : Person(size_name, name)
        , m_empID { empID }
        , m_deptName { new char[size_deptName] }
    {
        for (int i {}; i < size_deptName; ++i) {
            m_deptName[i] = deptName[i];
        }
    }

    ~Employee()
    {
        std::cout << "Employee destr. called" << std::endl;
        delete[] m_deptName;
    }
};

int main()
{
    Person* p[] { new Person { 5, "Rahul" }, new Employee { 5, "Sudha", 1010, 2, "HR" } };
    delete p[0];
    delete p[1];
}
/*
 * On exit output will be:
 *
 * Person destr. called   ---> For Rahul
 * Employee destr. called ---> For Sudha
 * Person destr. called   ---> For Sudha
 *
 *
 * If Person destructor was not marked virtual then the output will be
 * Person destr called    ---> For Rahul
 * Person destr called    ---> For Sudha
 *
 * Sudha's Employee destr never gets called because
 * the p pointer has no virtual table to gather information
 * about whether Sudha has a destructor of its own
 * since its pointer to a Person type it looks for
 * a destructor in the scope of a Person class , i.e., a
 * Person destructor. This causes a memory leak of deptName of Sudha
 */