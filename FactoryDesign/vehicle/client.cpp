#include<iostream>
using namespace std;
#include "vehicle_factory.hpp"
int main()
{
    string vehicleType;
    cin >>vehicleType;
    Vehicle *vehicle = VehicleFactory::getVehicle(vehicleType);
    vehicle->createVehicle();
    return 0;
}