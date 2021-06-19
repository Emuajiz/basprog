#include <iostream>
#include <new> 
using namespace std;

class Employee {
    public:
    virtual void salary() { cout << 'A';}
};

class Manager : public Employee {
    virtual void salary() { cout << 'B';}
};

void globalSalary(Employee *emp)
{
    emp->salary();
}

int main()
{
    Employee *e1 = new Employee;
    Employee *e2 = new Manager;
    globalSalary(e1);
    globalSalary(e2);
    return 0;
}