#include <iostream>

using namespace std;

class NetworkDevice {
public:
    // use const - This method will not modify the internal state of the object.
    // promising that clone() is a read-only operation — it doesn’t change the current object.
    virtual NetworkDevice* clone() const = 0;
    virtual void display() const = 0;
    virtual void update(string newName) = 0; // Update the device's name
};

class Router : public NetworkDevice {
private:
    string name;
    string ip;
    string securityPolicy;
public:
    Router(string name, string ip, string securityPolicy)
        : name(move(name)), ip(move(ip)), securityPolicy(move(securityPolicy)) {}

    //*this refers to the current object (the one calling clone()).
    //calls the copy constructor to create a new object that's a copy of the current one.
    //new allocates that object on the heap.
    NetworkDevice* clone() const override {
        // Clone returns deep copy
        // alter native of last line to return deep copy of object 
        //ConcretePrototype2 copy = *this;              // Copy constructor is called
        //return new ConcretePrototype2(copy);  	
        return new Router(*this);
    }


    void display() const override {
        cout << "Router - Name: " << name << ", IP: " << ip << ", Security Policy: " << securityPolicy << endl;
    }

    void update(string newName) override {
        name = move(newName);
    }
};

class Switch : public NetworkDevice {
private:
    string name;
    string protocol;
public:
    Switch(string name, string protocol)
        : name(move(name)), protocol(move(protocol)) {}

    NetworkDevice* clone() const override {
        return new Switch(*this);
    }

    void display() const override {
        cout << "Switch - Name: " << name << ", Protocol: " << protocol << endl;
    }

    void update(string newName) override {
        name = move(newName);
    }

};

int main() {
    // Create prototype instances of a router and a switch
    NetworkDevice* routerPrototype = new Router("Router A", "192.168.1.1", "Firewall Enabled");
    NetworkDevice* switchPrototype = new Switch("Switch X", "Ethernet");

    // Clone and display router and switch devices
    NetworkDevice* routerClone = routerPrototype->clone();
    NetworkDevice* switchClone = switchPrototype->clone();

    cout << "Router Clone:" << endl;
    routerClone->display();

    cout << "\nSwitch Clone:" << endl;
    switchClone->display();

    // Update the names of the clones
    routerClone->update("Router B");
    switchClone->update("Switch Y");

    cout << "\nUpdated Router Clone:" << endl;
    routerClone->display();

    cout << "\nUpdated Switch Clone:" << endl;
    switchClone->display();

    // Clean up
    delete routerPrototype;
    delete switchPrototype;
    delete routerClone;
    delete switchClone;

    return 0;
}