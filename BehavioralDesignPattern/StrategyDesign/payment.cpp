#include<iostream>
using namespace std;

// Interface of strategy
class Payment {
public:
    virtual ~Payment() {}
    virtual void pay(double amount) = 0;
};

// concrete strategy
class CreditCardPayment : public Payment {
public:
    void pay(double amount) {
        std::cout << "Paid using credit card." << std::endl;
    }
};

class PayPalPayment : public Payment {
public:
    void pay(double amount) {
        std::cout << "Paid using PayPal." << std::endl;
    }
};

class UPIPayment : public Payment {
public:
    void pay(double amount) {
        std::cout << "Paid using UPI." << std::endl;
    }
};

class CashPayment : public Payment {
public:
    void pay(double amount) {
        std::cout << "Paid using cash." << std::endl;
    }
};


class PaymentFactory {
public:
    static Payment* createPayment(string paymentMethod) {
        if (paymentMethod == "CreditCard") {
            return new CreditCardPayment();
        } else if (paymentMethod == "PayPal") {
            return new PayPalPayment();
        } else if (paymentMethod == "UPI") {
            return new UPIPayment();
        } else if (paymentMethod == "Cash") {
            return new CashPayment();
        } else {
            return nullptr;
        }
    }
};

// context 

class PaymentProcessor {  
    private:
        Payment * paymentStrategy = nullptr;
public:
    void processPayment(string paymentMethod, double amount = 0.0) {
        if(paymentStrategy) {
             delete paymentStrategy;  // Prevent memory leak
        }
        paymentStrategy = PaymentFactory::createPayment(paymentMethod);
        if (paymentStrategy != nullptr) {
            paymentStrategy->pay(amount);
        } else {
            std::cout << "Invalid payment method." << std::endl;
        }
    }
    ~PaymentProcessor()
    {
        delete paymentStrategy;
    }
};


int main()
{
    PaymentProcessor paymentProcessor;
    paymentProcessor.processPayment("CreditCard", 334);
    paymentProcessor.processPayment("PayPal", 89.99);
    paymentProcessor.processPayment("UPI",67.88);
    paymentProcessor.processPayment("Cash",78.3);
    return 0;
}