#ifndef infoLogger_hpp
#define infoLogger_hpp
#include "ilogger.hpp"
class infoLogger : public ILogger
{
public:
    void log(const string& message);
};

#endif  