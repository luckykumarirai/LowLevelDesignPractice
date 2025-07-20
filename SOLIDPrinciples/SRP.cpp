#include<iostream>
using namespace std;

// one clas has one reseans to change  
// here we voilating SRP - employee class should only save employee data not to Log
// class Employee{
//     public:
//     void addEmployee(){
//         cout<<"add employee";
//     }
//     void removeEmployee(){
//         cout<<"remove employee";
//     }
//     // If logging requirements change (different log format, log to database instead of console)
//     void Log(){
//         cout<<"log employee ingormation";
//     }
// };


// To correct his we need to impliment SRP
class IEmployeeLogger{
    public: 
    virtual void LogInfo(string message)=0;
    virtual ~IEmployeeLogger() {}
};

class EmployeeLogger : public IEmployeeLogger{
    public:
    void LogInfo(string message){
        cout<<message<<endl;
    }
};

class DatabaseLogger : public IEmployeeLogger{
    public:
    void LogInfo(string message){
        cout<<message+" = database log"<<endl;
    }
};

class Employee
{
private:
    IEmployeeLogger* logger;

    public:
        // Constructor Injection
        Employee(IEmployeeLogger* logger) : logger(logger) {}

        void addEmployee(){
            logger->LogInfo("Employee added");
        }
        void removeEmployee(){
            logger->LogInfo("Employee removed.");
        }
};

int main()
{
    Employee emp(new EmployeeLogger());
    emp.addEmployee();
    emp.removeEmployee();

    // Databse logger
    Employee emp1(new DatabaseLogger());
    emp1.addEmployee();
    emp1.removeEmployee();

    return 0;
}