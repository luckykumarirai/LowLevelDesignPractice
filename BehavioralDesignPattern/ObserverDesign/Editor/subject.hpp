#ifndef Subject_hpp
#define Subject_hpp

#include "listener.hpp"

class Subject {   
public:
    virtual void attach(Listener * lisner) = 0;
    virtual void detach(Listener * lisner) = 0;
    virtual void notify() = 0;
};
#endif