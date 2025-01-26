#ifndef abstractFactory_hpp
#define abstractFactory_hpp

#include "ilogger_factory.hpp"
#include "common.hpp"
#include "errorLoggerFactory.hpp"
#include "infoLoggerFactory.hpp"

class AbstractFactory{
    public:
    static ILoggerFactory* createLoggerFactory(LoggerType type){
        if (type == LoggerType::INFO  )            
        {
            return new InfoLoggerFactory();
        }
        else if (type == LoggerType::ERROR)
        {
            return new ErrorLoggerFactory();
        }
        return nullptr;
    }
};

#endif