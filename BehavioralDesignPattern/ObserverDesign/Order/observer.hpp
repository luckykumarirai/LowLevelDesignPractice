#ifndef OBSERVER_HPP
#define OBSERVER_HPP


// A forward declaration is a declaration of a class without defining it. 
//It tells the compiler that a class exists but does not include its full definition.

// subject depends on observer and observer depends on subject that create circular dependency

class Subject;  // Forward declaration

class Observer {
public:
    virtual void update(Subject* subject) = 0;
    virtual ~Observer() {}  // Virtual destructor for proper cleanup
};

#endif

