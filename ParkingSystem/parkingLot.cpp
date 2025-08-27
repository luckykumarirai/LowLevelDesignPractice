#include<iostream>
using  namespace std;
#include<vector>
#include<map>
#include <chrono>
#include <ctime>
#include<math.h>
//---------------------Vehicle Model---------------------------------------------------------------------------------
enum class VehicleType { CAR, BIKE, TRUCK };

// abtrcat class for vehicle -> inherite by car , bike
class Vehicle{
protected: 
    string licenseNumber;

public:
    Vehicle(string licenseNumber) : licenseNumber(licenseNumber) {}
    string getLicenseNumber() const {
        return licenseNumber;
    }
    virtual VehicleType getVehicletype() = 0;
};

// concreate class that has to implement pure virtual class method 
class Car: public Vehicle{
    public:
    Car(string licenseNumber): Vehicle(licenseNumber){};

    VehicleType getVehicletype() override 
    {
        return VehicleType::CAR;
    }

};

class Bike: public Vehicle{
    public:
    Bike(string licenseNumber): Vehicle(licenseNumber){};

    VehicleType getVehicletype() override 
    {
        return VehicleType::BIKE;
    }

};

//----------------------Ticket class--------------------------------------

class Ticket{
  private:
    int id;
    string vehicleId;
    int slotId;
    int floorNumber;
    std::chrono::system_clock::time_point entryTime;
    std::chrono::system_clock::time_point exitTime;
    VehicleType vehicleType;

public:


   Ticket(int id, string vehicleId, int slotId, int floorNumber, VehicleType type)
        : id(id), vehicleId(vehicleId), slotId(slotId), floorNumber(floorNumber),
          vehicleType(type) {
        entryTime = chrono::system_clock::now();
    } 
          
     // Set exit time
    void setExitTime() {
            exitTime = entryTime + std::chrono::hours(2);
    }

    // Calculate duration
    long getDuration() {
        auto duration = std::chrono::duration_cast<std::chrono::minutes>(exitTime - entryTime);
        return duration.count();
    }

    VehicleType getVehicleType() const { return vehicleType; }

    void print() {
        auto etime = std::chrono::system_clock::to_time_t(entryTime);
        cout << "Ticket ID: " << id
            << " | Vehicle: " << vehicleId
            << " | Floor: " << floorNumber
            << " | Slot: " << slotId
            << " | Entry: " << std::ctime(&etime);
    }

    int getFloorNumber() { return floorNumber; }
    int getSlotId() { return slotId; }

};


// -----------------------------------Parking Slot---------------------------------------------------------

// abstract class for slot

class ParkingSlot{
    int id;
    bool isAvailable;
    Vehicle *vehicle;
public:
    ParkingSlot(int id): id(id),isAvailable(true), vehicle(nullptr){}
    virtual ~ParkingSlot() = default;

    virtual bool canFit(Vehicle* v) = 0;

    int getId() const { return id; }

    bool getAvailability() const { return isAvailable; }

    void park(Vehicle *v)
    {
        // park if correct vehicle type slloted to slot 
        if(isAvailable && canFit(v))
        {
            vehicle=v;
            isAvailable=false;
            cout << "Vehicle " << v->getLicenseNumber()
                 << " parked in slot " << id << endl;
        }
        else {
            cout << "Slot " << id << " already occupied!\n";
        }
          
    }
    void remoVehicle()
    {
        if (!isAvailable) {
            vehicle = nullptr;
            isAvailable = true;
        }
    }
};

class CarSlot : public ParkingSlot{
    public:
    CarSlot(int id) : ParkingSlot(id){}
    bool canFit( Vehicle *v) override 
    {
        if(v->getVehicletype()==VehicleType::CAR)
        {
            return true;
        }
        else
            return false;
    }
};

class BikeSlot : public ParkingSlot{
    public:
    BikeSlot(int id) : ParkingSlot(id){}
    bool canFit( Vehicle *v) override 
    {
        if(v->getVehicletype()==VehicleType::BIKE)
        {
            return true;
        }
        else
            return false;
    }
};

// -------------------------------------------Parking floor ---------------------------------------------------------

class ParkingFloor{
    private:
        int floorNumber;
        vector<ParkingSlot*> slots;
    public:
      ParkingFloor(int num, int bikeSlots, int carSlots) : floorNumber(num) {
            int idCounter = 1;
            for (int i = 0; i < carSlots; i++) {
                slots.push_back(new CarSlot(idCounter++));
            }
            for (int i = 0; i < bikeSlots; i++) {
                slots.push_back(new BikeSlot(idCounter++));
            }
        }
        //getter 
        int getFloorNumber()
        {
            return floorNumber;
        }
        
        //getter
        vector<ParkingSlot*>& getSlots() {
             return slots;
        }

        int countAvailableSlot() const 
        {
            int count=0;
            for(ParkingSlot *it: slots)
            {
                if(it->getAvailability())
                {
                    count++;
                }
            }
            return count;
        }
        ParkingSlot* findAvailableSlot(Vehicle* v) {
            for (auto* s : slots) {
                if (s->getAvailability() && s->canFit(v)) return s;
            }
            return nullptr;
        }
};


//-------------------Pricing claculation strategy------------------------------

// interface -  Different strategy to calculate  pricing
class PricingCalculator
{
    public: 
        virtual double cal(Ticket *t1)=0;
        virtual ~PricingCalculator() = default;
};

class Hourly : public PricingCalculator
{
    private: 
        double price;
    public:
        Hourly(double price=20.5)
        {
           this-> price=price;
        }
        double cal(Ticket *t) override {
            int totalTime = t->getDuration(); // in minutes
            double hours = ceil(totalTime / 60.0);  // round up to full hour
            return hours * price;
        }
};

class SlotBasis : public PricingCalculator
{
    private: 
        map<string, double> price;
    public:
        SlotBasis(map<string, double> price)
        {
            this-> price=price;
        }
        double cal(Ticket *t) override
        {
            int totalTime = t->getDuration();
            string type;
            if(t->getVehicleType() == VehicleType::BIKE)
            {
                return price["CAR"]*totalTime;
            }
            else if(t->getVehicleType() == VehicleType::CAR)
            {
                return price["BIKE"]*totalTime;
            }
        }
};


// Parking Lot - orchestrator (delegates to ParkingFloor, which delegates to ParkingSlot).  -------------------------------

class ParkingLot{
    private:
    vector<ParkingFloor*>floors;
    int ticketCounter = 1;

    public:
    ParkingLot(int floorCount, int carslotsPerFloor, int bikeslotsPerFloor) {
        for (int i = 1; i <= floorCount; i++) {
            floors.push_back(new ParkingFloor(i, carslotsPerFloor, bikeslotsPerFloor));
        }
    }
    ~ParkingLot() {
        for (auto* f : floors) {
            for (auto* s : f->getSlots()) delete s;
            delete f;
        }
    }


    void getavailablity() {
        for (auto *floor : floors) {
            for (auto *slot : floor->getSlots()) {
                cout << "On floor number " << floor->getFloorNumber()
                    << ", slot " << slot->getId()
                    << " is " << (slot->getAvailability() ? "available" : "occupied")
                    << endl;
            }
        }
    }

   
    Ticket* parkVehicle(Vehicle* v) {
        for (auto* floor : floors) {
            ParkingSlot* slot = floor->findAvailableSlot(v);
            if (slot != nullptr) {
                slot->park(v);
                return new Ticket(ticketCounter++, v->getLicenseNumber(),
                                slot->getId(), floor->getFloorNumber(),
                                v->getVehicletype());
            }
        }
        cout << "No available slots for vehicle " << v->getLicenseNumber() << endl;
        return nullptr;
    }
    
    void unparkVehicle(Ticket* t) {
        for (auto* floor : floors) {
            if (floor->getFloorNumber() == t->getFloorNumber()) {
                for (auto* slot : floor->getSlots()) {
                    if (slot->getId() == t->getSlotId()) {
                        slot->remoVehicle();
                        cout << "Vehicle with Ticket " << t->getSlotId()
                             << " has been unparked." << endl;
                        return;
                    }
                }
            }
        }
        cout << "Invalid Ticket!" << endl;
    }

    double calculatePrice(Ticket* t, PricingCalculator* strategy)
    {
        t->setExitTime();  // mark exit
        return strategy->cal(t);
    }

};



int main()
{
    ParkingLot lot(2, 2, 2);
    Vehicle *v1 = new Car("BR9087");
    Vehicle *v2 = new Bike("TL234");

    Ticket* t1 = lot.parkVehicle(v1);
    Ticket* t2 = lot.parkVehicle(v2);

    lot.getavailablity();

    // simulate exit for v1
    lot.unparkVehicle(t1);

    PricingCalculator* hourly = new Hourly(2.6);
    double price = lot.calculatePrice(t1, hourly);
    cout << "Parking Price = " << price << endl;

    delete v1;
    delete v2;
    delete t1;
    delete t2;
    delete hourly;

    return 0;
}
