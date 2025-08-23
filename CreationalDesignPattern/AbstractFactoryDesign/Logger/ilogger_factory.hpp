#ifndef iloggerFactorty_hpp
#define iloggerFactorty_hpp

#include "ilogger.hpp"
#include "errorLogger.hpp"
#include "infoLogger.hpp"   

class ILoggerFactory {
public:
    virtual ILogger *createLogger()=0;

    virtual ~ILoggerFactory() {}
};

#endif