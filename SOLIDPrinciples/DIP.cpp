#include<iostream>
using namespace std;

// voilating DIP - Employee class should only save employee data not to Log
// class FileLogger {
//     public:
//         void log(const string& message) {
//             cout << "[File] " << message << endl;
//         }
//     };
    
//     class OrderService {
//     public:
//         void placeOrder() {
//             FileLogger logger;
//             logger.log("Order placed successfully."); // ❌ tightly coupled to FileLogger
//         }
//     };

// Abstraction
class ILogger {
    public:
        virtual void log(const string& message) = 0;
        virtual ~ILogger() {}
    };
    
    // Concrete logger implementations
    class ConsoleLogger : public ILogger {
    public:
        void log(const string& message) override {
            cout << "[Console] " << message << endl;
        }
    };
    
    // High-level module depends on ILogger, not ConsoleLogger
    class OrderService {
    private:
        ILogger* logger;
    
    public:
        // Dependency Injection via constructor
        OrderService(ILogger* logger) : logger(logger) {}
    
        void placeOrder() {
            logger->log("Order placed successfully.");
        }
    };
    
    int main() {
        ConsoleLogger consoleLogger;
        OrderService service(&consoleLogger);
        service.placeOrder();
    
        return 0;
    }