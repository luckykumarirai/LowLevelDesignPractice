#include<iostream>
using namespace std;    

#include "observer.hpp"
#include "subject.hpp"

class Delivery: public Observer{
    private:
        string Name;
    public:
        Delivery(string name) :Name(name){} 
        void update(Subject * subject){
            cout << "Delivery " << Name << " received an order update." << endl;
        }
};