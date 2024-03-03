#ifndef VehicleFactory_hpp
#define VehicleFactory_hpp

#include "vehicle.hpp"
#include "car.hpp"
#include "bike.hpp"
#include<iostream>
using namespace std;

class VehicleFactory : public Vehicle{
    public: 
        static Vehicle getVehicle(string vehicleType)
};

#endif