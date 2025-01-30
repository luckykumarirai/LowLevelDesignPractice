#ifndef vehicle_hpp
#define vehicle_hpp
class Vehicle{
    public:
    virtual void createVehicle()=0;
};
#endif

//Include Guards (#ifndef, #define, #endif): - Prevents the header file from being included multiple times, which can cause erro
//These declarations are shared between multiple .cpp files.
// Header files are typically used to separate the interface of a program from its implementation, improving code organization and reusability.
// A header file contains declarations only (no function implementations, except for inline functions or templates).