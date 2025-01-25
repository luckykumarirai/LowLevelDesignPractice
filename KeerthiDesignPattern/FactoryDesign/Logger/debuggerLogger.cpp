#include "debuggerLogger.hpp"
#include<iostream>
using namespace std;

void DebuggerLoger::log(const string &msg){
    cout << "Debugger Logger="<< msg<<endl;
