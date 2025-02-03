#ifndef SUBJECT_HPP
#define SUBJECT_HPP

#include <iostream>
#include <vector>
using namespace std;

class Observer; // Forward declaration of Observer

class Subject {
public:
    virtual void registerObserver(Observer* observer) = 0;
    virtual void removeObserver(Observer* observer) = 0;
    virtual void notifyObserver() = 0;
    virtual ~Subject() {}  // Virtual destructor to prevent memory leaks
};

#endif
