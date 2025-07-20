#include<iostream>
#include <memory>
#include <vector>
using namespace std;

// voilating open close principles - 
// if we need to add new employee type we need to change the code
// class Employee{
//     private:
//         int salary;
//         string EmployeeType;
//     public: 
//     void getSalary()
//     {
//         cout << "salary";
//     }
//     void getBonus(){
//         if(EmployeeType=="Manager")
//         {
//             cout<<"Manager Bonus";
//         }
//         else if(EmployeeType=="Developer")
//         {
//             cout<<"Developer Bonus";
//         }
//     }
// };

class IEmployee{
    public:
    virtual void getSalary()=0;
    virtual void getBonus()=0;
};

class Manager : public IEmployee{
    public:
    void getSalary()
    {
        cout << "Manager Salary: ₹100,000" << endl;
    }
    void getBonus(){
        cout << "Manager Bonus: ₹20,000" << endl;
    }
};
class Developer : public IEmployee{
    public:
    void getSalary()
    {
        cout << "Developer Salary: ₹80,000" << endl;
    }
    void getBonus(){
        cout << "Developer Bonus: ₹10,000" << endl;
    }
};

/*************  ✨ Windsurf Command ⭐  *************/
/**
 * The main function demonstrates the Open/Closed Principle by using polymorphism.
 * It creates instances of Manager and Developer classes, both inheriting from 
 * the IEmployee interface, and calls their respective getSalary and getBonus 
 * methods. This allows for easy extension of new employee types without modifying 
 * existing code.
 */

/*******  43ff8422-cd1e-4914-96f7-a0454012cd45  *******/
int main()
{
    // IEmployee *emp = new Manager();
    // emp->getSalary();
    // emp->getBonus();

    // IEmployee *emp1 = new Developer();
    // emp1->getSalary();
    // emp1->getBonus();


    vector<unique_ptr<IEmployee>> employees;

    employees.push_back(make_unique<Manager>());
    employees.push_back(make_unique<Developer>());

    // Polymorphic calls
    for (const auto& emp : employees) {
        emp->getSalary();
        emp->getBonus();
    }

    return 0;
}