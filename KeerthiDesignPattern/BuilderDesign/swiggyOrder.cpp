
#include<iostream>
using namespace std;  
// in swiggy while order we have option to add dish, spice level, add on, special instructions and payment method

// Product class 
class Order {
    public:
        string dish;
        string spiceLevel;
        string addOn;
        string specialInstuctions;
        string paymentMethod;
    void showOrder() {
        cout<< "Order details...........................:\nDish: " << dish << "\nSpice Level: " << spiceLevel << "\nAdd On: " << addOn << "\nSpecial Instructions: " << specialInstuctions << "\nPayment Method: " << paymentMethod << endl;
    }
};

// Abstarct builder class 
class OrderBuilder {
    public:
        virtual void setDish() = 0;
        virtual void setSpiceLevel() = 0;
        virtual void setAddOn() = 0;
        virtual void setSpecialInstructions() = 0;
        virtual void setPaymentMethod() = 0;
        virtual Order *getOrder() = 0;
        virtual ~OrderBuilder() {}
};

//concrete builder 
class CustomOrderBuilder: public OrderBuilder {
    private:
        Order *order;
    public:
        CustomOrderBuilder() {
            order = new Order();
        }
        ~CustomOrderBuilder() { delete order; }
    public:
        void setDish() {
            order->dish = "Paneer";
        }
        void setSpiceLevel() {
            order->spiceLevel = "Medium";
        }
        void setAddOn() {
            order->addOn = "No Add On";
        }
        void setSpecialInstructions() {
            order->specialInstuctions = "No Special Instructions";
        }
        void setPaymentMethod() {
            order->paymentMethod = "Cash";
        }
        Order * getOrder() { 
            Order* result = order; // Transfer ownership
            order = nullptr;       // Prevent double delete
            return result; 
        }
};

// director class
class OrderDirector {
private:
    OrderBuilder* builder;

public:
    void setBuilder(OrderBuilder* builder) {
        this->builder = builder;
    }

    // Builds a standard order
    void constructOrder() {
        builder->setDish();
        builder->setSpiceLevel();
        builder->setAddOn();
        builder->setSpecialInstructions();
        builder->setPaymentMethod();
    }
};

int main()
{
    // Create a concrete builder
     CustomOrderBuilder builder;

    // Create the director and assign the builder
    OrderDirector director;
    director.setBuilder(&builder);

    // Construct the order
    director.constructOrder();

    // Get the constructed order
    Order* order = builder.getOrder();
    order->showOrder();

    // Clean up
    delete order;

    return 0;
}
