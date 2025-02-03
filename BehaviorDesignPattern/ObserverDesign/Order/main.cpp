#include<iostream>
using namespace std;

#include "customerObserber.hpp"
#include "deliveryObserver.hpp"
#include "order.hpp"  // Concrete subject

int main(){

    // create an order
    Order order1(123, "Pizza order");

    Customer observer1("customer1");
    order1.registerObserver(&observer1);
    

    Delivery observer2("delivery1");
    order1.registerObserver(&observer2);
    
    order1.notifyObserver();

    return 0;
}