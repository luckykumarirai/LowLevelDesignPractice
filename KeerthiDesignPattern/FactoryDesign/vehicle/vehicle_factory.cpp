#include "vehicle_factory.hpp"

Vehicle *VehicleFactory :: getVehicle(string vehicleType){
    Vehicle * vehicle;
    if(vehicleType =="car")
    {
        vehicle = new Car();
    }
    else if(vehicleType =="bike")
    { 
        vehicle = new Bike();
    }
    else{
        cout << "not support another vehicle type "<<endl;
    }
    return vehicle;
}