#ifndef infoLoggerFactory_hpp
#define infoLoggerFactory_hpp

#include "ilogger_factory.hpp"
#include "infoLogger.hpp"

class  InfoLoggerFactory : public ILoggerFactory {
public:
    ILogger *createLogger() {
        return new InfoLogger();
    }
};
#endif