#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <iostream>
#include <mutex>

class Logger {
public:
    static Logger* getLogger();
    void Log(std::string msg);

    // Destructor to clean up resources
    ~Logger();

private:
    static int ctr;
    static Logger* loggerInstance;
    static std::mutex mtx;
    Logger();
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;

};

#endif
