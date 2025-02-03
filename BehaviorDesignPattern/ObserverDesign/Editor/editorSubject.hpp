#include "subject.hpp"
#include "listener.hpp"
#include<iostream>
using namespace std;
#include<vector>

#ifndef EditorLisner_hpp
#define EditorLisner_hpp

class EditorSubject : public Subject {
private: 
     int id;
        string OrderName;
        vector<Listener*> lisners;
public:
    void attach(Listener * lisner) override {
        lisners.push_back(lisner);
    }
    void detach(Listener * lisner) override {
        for (auto it = lisners.begin(); it != lisners.end(); ++it) {
                if (*it == lisner) {
                    lisners.erase(it);
                    break;  // Stop after removing the first match
                }
        } 
    }
    void notify() override {
        for (Listener* lisner : lisners) {
            lisner->update("File saved");
        }
    }
};

#endif