#include <iostream>

using namespace std;

// Define the abstract base class for order handlers.
class OrderHandler {
protected:
    OrderHandler* nextHandler;

public:
    OrderHandler() : nextHandler(nullptr) {}

    void setNextHandler(OrderHandler* nextHandler) {
        this->nextHandler = nextHandler;
    }

    virtual void processOrder(const string& order) = 0;

    virtual ~OrderHandler() {
        delete nextHandler; // Recursively delete next handlers to prevent memory leaks
    }
};

// Concrete handler for order validation.
class OrderValidationHandler : public OrderHandler {
public:
    void processOrder(const string& order) override {
        cout << "Validating order: " << order << endl;

        if (nextHandler)
            nextHandler->processOrder(order);
    }

    ~OrderValidationHandler() {
        cout << "OrderValidationHandler destructor called" << endl;
    }
};

// Concrete handler for payment processing.
class PaymentProcessingHandler : public OrderHandler {
public:
    void processOrder(const string& order) override {
        cout << "Processing payment for order: " << order << endl;

        if (nextHandler)
            nextHandler->processOrder(order);
    }

    ~PaymentProcessingHandler() {
        cout << "PaymentProcessingHandler destructor called" << endl;
    }
};

// Concrete handler for order preparation.
class OrderPreparationHandler : public OrderHandler {
public:
    void processOrder(const string& order) override {
        cout << "Preparing order: " << order << endl;

        if (nextHandler)
            nextHandler->processOrder(order);
    }

    ~OrderPreparationHandler() {
        cout << "OrderPreparationHandler destructor called" << endl;
    }
};

// Concrete handler for delivery assignment.
class DeliveryAssignmentHandler : public OrderHandler {
public:
    void processOrder(const string& order) override {
        cout << "Assigning delivery for order: " << order << endl;

        if (nextHandler)
            nextHandler->processOrder(order);
    }

    ~DeliveryAssignmentHandler() {
        cout << "DeliveryAssignmentHandler destructor called" << endl;
    }
};

// Concrete handler for order tracking.
class OrderTrackingHandler : public OrderHandler {
public:
    void processOrder(const string& order) override {
        cout << "Tracking order: " << order << endl;

        if (nextHandler)
            nextHandler->processOrder(order);
    }

    ~OrderTrackingHandler() {
        cout << "OrderTrackingHandler destructor called" << endl;
    }
};

int main() {
    // Create handlers
    OrderValidationHandler* validationHandler = new OrderValidationHandler();
    PaymentProcessingHandler* paymentHandler = new PaymentProcessingHandler();
    OrderPreparationHandler* preparationHandler = new OrderPreparationHandler();
    DeliveryAssignmentHandler* deliveryHandler = new DeliveryAssignmentHandler();
    OrderTrackingHandler* trackingHandler = new OrderTrackingHandler();

    // Set up the chain dynamically
    validationHandler->setNextHandler(paymentHandler);
    paymentHandler->setNextHandler(preparationHandler);
    preparationHandler->setNextHandler(deliveryHandler);
    deliveryHandler->setNextHandler(trackingHandler);

    // Simulate an order being placed
    string order = "Pizza";
    validationHandler->processOrder(order);

    // Clean up memory
    delete validationHandler;

    return 0;
}
