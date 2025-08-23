#ifndef logger_hpp
#define logger_hpp
#include "common.hpp"
class ILogger
{
    public:
      virtual void log(const string& message)=0;
};
#endif