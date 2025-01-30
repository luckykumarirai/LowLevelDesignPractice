#include "common.hpp"
#include "abstractFactory.hpp"
int main()
{
    ILoggerFactory* infoLogger = AbstractFactory::createLoggerFactory(LoggerType::INFO);
    ILogger *info = infoLogger->createLogger();
    info->log("this is an error message");

    ILoggerFactory* errorLogger = AbstractFactory::createLoggerFactory(LoggerType::ERROR);
    ILogger *error = errorLogger->createLogger();
    error->log("This is an info message");
    

    return 0;
}