#ifndef infoLogger_hpp
#define infoLogger_hpp
#include "ilogger.hpp"
class InfoLogger:public ILogger {
    public:
     void log(const string& message);
};

#endif