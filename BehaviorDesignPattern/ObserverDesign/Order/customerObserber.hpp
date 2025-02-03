#include<iostream>
using namespace std;    

#include "observer.hpp"
#include "subject.hpp"

class Customer: public Observer{
    private:
        string Name;

    public:
        Customer(string name) :Name(name){}
        void update(Subject * subject){
            cout << "Customer " << Name << " received an order update." << endl;
        }
};