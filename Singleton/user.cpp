#include <iostream>
#include <thread>
#include "logger.hpp"

void user1() {
    Logger *logger1 = Logger::getLogger();
    logger1->Log("this msg is from user 1");
}

void user2() {
    Logger *logger2 = Logger::getLogger();
    logger2->Log("this msg from user 2");
}

int main() {
    std::thread t1(user1);
    std::thread t2(user2);

    t1.join();
    t2.join();

    // Clean up the logger instance
    delete Logger::getLogger();

    return 0;
}
