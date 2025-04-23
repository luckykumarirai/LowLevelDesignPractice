
#ifndef NOTIFICATIONMANAGER_HPP
#define NOTIFICATIONMANAGER_HPP

#include<iostream>
#include<mutex>
using namespace std;

class NotificationManager{
    private:
        static NotificationManager *NotificationManagerInstance;
        static mutex m;
        NotificationManager();
        NotificationManager(const NotificationManager &) = delete;
        NotificationManager &operator=(const NotificationManager &) = delete;
        void sendEmail(string messages);
        void pushNotification(string messages);
        void sendSMS(string messages);

    public:
        // define static - for staic method no need to call by instance it directly call by class::methodname
        static NotificationManager * getInstance();
        void sendNotification(string message, string channel);
};
#endif