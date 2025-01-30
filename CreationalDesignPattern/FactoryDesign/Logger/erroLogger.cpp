#include "errorLogger.hpp"
#include<iostream>
using namespace std;
void ErrorLogger::log(const string &msg){
    cout << "Error Logger="<< msg<<endl;
}