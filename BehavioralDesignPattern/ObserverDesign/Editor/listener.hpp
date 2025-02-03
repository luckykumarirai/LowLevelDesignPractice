#include<iostream>
#ifndef Lisner_hpp
#define Lisner_hpp

class Listener
{
    public:
     virtual void update(const std::string &filename) = 0;
};

#endif