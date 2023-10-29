#include <string>
#include <iostream>

struct Student {
    virtual char const* getDept() const = 0;
};

struct EngineerStudent : Student {
    char const* getDept() const override
    {
        return "Engineer";
    }
};

struct MedicineStudent : Student {
    char const* getDept() const override
    {
        return "Medicine";
    }
};

struct ScienceStudent : Student {
    char const* getDept() const override
    {
        return "Science";
    }
};

int main()
{
    EngineerStudent engg_stu {};
    MedicineStudent med_stu {};
    ScienceStudent sci_stu {};

    Student* stu[] { &engg_stu, &med_stu, &sci_stu };
    std::cout << stu[0]->getDept() << "\n" /* Should print Engineer */
              << stu[1]->getDept() << "\n" /* Should print Medicine */
              << stu[2]->getDept() << "\n"; /* Should print Science */
}