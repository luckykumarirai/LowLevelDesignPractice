#ifndef errorLoggerFactory_hpp
#define errorLoggerFactory_hpp

#include "ilogger_factory.hpp"
#include "errorLogger.hpp"

class ErrorLoggerFactory : public ILoggerFactory
{
    public:
        ILogger *createLogger() {
            return new ErrorLogger();
        }
};
#endif