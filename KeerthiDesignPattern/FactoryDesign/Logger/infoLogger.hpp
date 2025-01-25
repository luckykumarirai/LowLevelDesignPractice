#ifndef errorLogger_hpp
#define errorLogger_hpp
#include "ilogger.hpp"
class infoLogger : public ILogger
{
public:
    void log(const string& message);
};

#endif  