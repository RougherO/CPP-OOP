#include <string>

struct Person {
    const std::string& getName() const
    {
        /*
         * return name of person
         */
    }
};

struct Employee_no_v : Person {
};

struct Employee : virtual Person {
};

struct Student_no_v : Person {
};

struct Student : virtual Person {
};

struct Manager_no_v : Student_no_v, Employee_no_v {
};

struct Manager : Student, Employee {
};

int main()
{
    Manager_no_v man_1;
    Manager man_2;

    /* man_1.getName();
     *
     * This call is ambiguous as it doesn't know which base class' getName() to call
     * For this we need to explicitly override the base class getName() and mention which one to use
     * in the class itself
     *
     * OR
     *
     * man_1.Employee_no_v::getName(); explicitly mention which base class version of getName to call
     * at the call site.
     */

    man_2.getName();
    /*
     * This is non-ambiguous since here only a single copy of class definition resides with the
     * base class and any call to getName() will call the base class version of getName() if they are
     * not overloaded in the derived class Employee and Student.
     */
}