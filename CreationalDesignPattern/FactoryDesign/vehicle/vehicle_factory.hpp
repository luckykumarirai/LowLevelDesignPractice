#ifndef vehicelFactory_hpp
#define vehicelFactory_hpp

#include "common.hpp"
#include "car.hpp"
#include "bike.hpp"

// function static - means no need to create an object of class
// access function using class itself
class VehicleFactory: public Vehicle{
    public:
        static Vehicle *getVehicle(string vehicleType);
};
#endif