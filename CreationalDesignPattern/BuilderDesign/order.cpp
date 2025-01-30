
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
    protected:
        Order order;
    public:
        virtual void setDish() = 0;
        virtual void setSpiceLevel() = 0;
        virtual void setAddOn() = 0;
        virtual void setSpecialInstructions() = 0;
        virtual void setPaymentMethod() = 0;
        Order getOrder() 
        {
            return order;
        }
};

//concrete builder 
class CutomeOrderBuilder: public OrderBuilder {
    public:
        void setDish() {
            order.dish = "Paneer";
        }
        void setSpiceLevel() {
            order.spiceLevel = "Medium";
        }
        void setAddOn() {
            order.addOn = "No Add On";
        }
        void setSpecialInstructions() {
            order.specialInstuctions = "No Special Instructions";
        }
        void setPaymentMethod() {
            order.paymentMethod = "Cash";
        }
};

// director class
class OrderDirector {
    public:
        Order createOrder(OrderBuilder &order) {
            order.setDish();
            order.setSpiceLevel();
            order.setAddOn();
            order.setSpecialInstructions();
            order.setPaymentMethod();
            return order.getOrder();
        }
};

int main()
{
    // creating a director object and passing builder object
    OrderDirector director;

    CutomeOrderBuilder builder;
    Order order = director.createOrder(builder);
    order.showOrder();
    return 0;
}
