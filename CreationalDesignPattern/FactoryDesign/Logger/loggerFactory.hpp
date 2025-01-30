#pragma once
#include "ilogger.hpp"
#include "debuggerLogger.hpp"
#include "infoLogger.hpp"
#include "errorLogger.hpp"

class ILoggerFactory : public ILogger{
    public:
        static ILogger* createLogger(LoggerType type);
};