#include "listener.hpp"

#ifndef EmailAlertLisner_hpp
#define EmailAlertLisner_hpp
class EmailAlertLisner : public Listener {
    private:
        std::string Name;

    public:
        EmailAlertLisner(std::string name) : Name(name) {}  
        void update(const std::string &filename) override {
        std::cout << "Logging " << filename << std::endl;
    }
};

#endif