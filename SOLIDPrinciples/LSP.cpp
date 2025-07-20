#include<iostream>
using namespace std;


// Voilation of Liskov Substitution Principle
// class Bird
// {
// public:
//     virtual void fly()
//     {
//         cout << "Bird is flying" << endl;
//     }
// };

// class Sparrow : public Bird {
//     public:
//     void fly() override {
//         cout << "Sparrow flies high!" << endl;
//     }
// };

// class Penguin : public Bird {
//     public:
//     void fly() override {
//         // Penguins can't fly, so we throw or do nothing
//         throw runtime_error("Penguins can't fly!");
//     }  
// };

// void makeBirdFly(Bird* b) {
//    b->fly(); // ❌ This will crash for Penguin
// }


class Bird {
    public:
        virtual void eat() = 0;
        virtual ~Bird() {}
};
    
class Flyable {
public:
    virtual void fly() = 0;
    virtual ~Flyable() {}
};
    
class Sparrow : public Bird, public Flyable {
public:
    void eat() override {
        cout << "Sparrow eats seeds" << endl;
    }

    void fly() override {
        cout << "Sparrow flies high!" << endl;
    }
};
    
class Penguin : public Bird {
public:
    void eat() override {
        cout << "Penguin eats fish" << endl;
    }

    // No fly method here — Penguin is not Flyable
};

void makeFly(Flyable* bird) {
    bird->fly(); // ✅ Works only for birds that can fly
}
    

int main() {
    Bird* penguin = new Penguin();
    Flyable* sparrow = new Sparrow();
    
    makeFly(sparrow); 
    penguin->eat();

    return 0;
}
    