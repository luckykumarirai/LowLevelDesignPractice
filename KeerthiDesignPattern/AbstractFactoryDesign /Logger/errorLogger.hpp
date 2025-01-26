#ifndef errorLogger_hpp
#define errorLogger_hpp
#include "ilogger.hpp"
class ErrorLogger: public ILogger {
    public:
      void log(const string& message);
};

#endif