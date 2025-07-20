#include<iostream>
using namespace std;


// to force to imlement any thing which is not required
// ISP - Interface Segregation Principle
// class Vehicle{
//     public: 
//      void drive()
//      {
//          cout<<"drive vehicle"<<endl;
//      }
//      void fly()
//      {
//          cout<<"fly vehicle"<<endl;
//      }
// };

// class Bike: public Vehicle{
//     public:
//     void drive()
//     {
//         cout<<"drive bike"<<endl;
//     }
//     void fly()
//     {
//         cout<<"fly bike is not working we have implemented "<<endl;
//     }
// };

class IFlya{
    public:
    virtual void fly()=0;
};
class IDrive{
    public:
    virtual void drive()=0;
};

class Bike:public IDrive{
    public:
    void drive()
    {
        cout<<"drive bike"<<endl;
    }
};

class flycar:public IFlya , public IDrive{
    public:
    void fly()
    {
        cout<<" lets  fly car"<<endl;
    }
    void drive()
    {
        cout<<"we can drive flyting car as well"<<endl;
    }
};

int main()
{
    Bike b1;
    b1.drive();
    flycar f1;
    f1.fly();
    f1.drive();
    return 0;
}