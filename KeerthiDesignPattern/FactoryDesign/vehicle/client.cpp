#include<iostream>
using namespace std;
//#include "vehicle.hpp"
#include "bike.hpp"
#include "car.hpp"
int main(){
    string vehicleType;
    cin >> vehicleType;
    Vehicle *v1;
    if (vehicleType == "car")
    {
        v1 = new Car();
    }
    else if (vehicleType == "bike")
    {
        v1 = new Bike();
    }
    v1->createVehicle();
    return 0;
}