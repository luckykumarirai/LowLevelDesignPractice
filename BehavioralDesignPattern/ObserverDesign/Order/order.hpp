
#ifndef ORDER_SUBJECT_HPP
#define ORDER_SUBJECT_HPP

#include<iostream>
using namespace std;

#include "subject.hpp"
#include "observer.hpp"

class Order: public Subject {
    private:
        int id;
        string OrderName;
        vector<Observer*> observers;
    public:
        Order(int id, string OrderName) : id(id), OrderName(OrderName) {}
        void registerObserver(Observer* observer) override
        {
            observers.push_back(observer);
        }
        void removeObserver(Observer* observer) override {
            for (auto it = observers.begin(); it != observers.end(); ++it) {
                if (*it == observer) {
                    observers.erase(it);
                    break;  // Stop after removing the first match
                }
            }   
        }
/*************  ✨ Codeium Command ⭐  *************/
        /**
         * Notifies all registered Observers of changes to the Subject.
         */
/******  333efc7a-b4fa-43c4-ab56-c01656093db5  *******/
        void notifyObserver() override {
            for (Observer* ob : observers) {  
                ob->update(this);
            }
        }
         virtual ~Order() {}
};

#endif