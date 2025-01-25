#include "loggerFactory.hpp"

ILogger *ILoggerFactory::createLogger(LoggerType type) {
    switch (type) {
        case LoggerType::DEBUG:
            return new DebuggerLoger();
        case LoggerType::INFO:
            return new infoLogger();
        case LoggerType::ERROR:
            return new ErrorLogger();
        default:
            return nullptr;
    }
}
