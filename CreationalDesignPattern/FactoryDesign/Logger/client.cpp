#include "loggerFactory.hpp"
#include "common.hpp"

int main() {
    ILogger *infoLogger = ILoggerFactory::createLogger(LoggerType::INFO);
    infoLogger->log("this is an error message");

    ILogger *errorLogger = ILoggerFactory::createLogger(LoggerType::ERROR);
    errorLogger->log("This is an info message");

    ILogger *debuggerLogger = ILoggerFactory::createLogger(LoggerType::DEBUG);
    debuggerLogger->log("This is a debug message");

    delete infoLogger;
    delete errorLogger; 
    delete debuggerLogger; 

    return 0;
}