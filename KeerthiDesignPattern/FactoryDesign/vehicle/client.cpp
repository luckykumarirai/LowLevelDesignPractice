#include<iostream>
using namespace std;
// #include "bike.hpp"
// #include "car.hpp"

#include "vehicle_factory.hpp"
int main(){
    string vehicleType;
    cin >> vehicleType;

    // we are going to use factory to create object bec in this everytime we have to tell client add skooty.hpp file and add one more condition like this
    // Vehicle *v1;
    // if (vehicleType == "car")
    // {
    //     v1 = new Car();
    // }
    // else if (vehicleType == "bike")
    // {
    //     v1 = new Bike();
    // }
    // else{
    //     cout << "not support another vehicle type "<<endl;
    // }
    // v1->createVehicle();


    // using factory design pattern it become more simpler to create object
    // if any change in factory class we don't have to change client code
    Vehicle *vehicle = VehicleFactory::getVehicle(vehicleType);
    vehicle->createVehicle();
    return 0;
}