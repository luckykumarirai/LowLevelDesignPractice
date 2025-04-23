#include "NotificationManager.hpp"

NotificationManager *NotificationManager::NotificationManagerInstance = nullptr;
mutex NotificationManager::m;

// different strategy to sent notification
void NotificationManager::sendEmail(string messages)
{
    cout << "Sending Email: " << messages << endl;
}
void NotificationManager::pushNotification(string messages)
{
    cout << "Sending Push Notification: " << messages << endl;
}
void NotificationManager::sendSMS(string messages){
    cout << "Sending SMS: " << messages << endl;
}

NotificationManager *NotificationManager::getInstance()
{
    if(NotificationManagerInstance == nullptr)
    {
        lock_guard<mutex> lock(m); // Thread-safe lock
        if (NotificationManagerInstance == nullptr)
        {
            NotificationManagerInstance = new NotificationManager();
        }
    }
    return NotificationManagerInstance;
}

void NotificationManager::sendNotification(string message, string channel)
{
    if(channel == "email")  
    {
       sendEmail(message);
    }
    else if(channel =="SMS")
    {
        sendSMS(message);
    }
    else if(channel =="pushNotification")
    {
        pushNotification(message);
    }
    else{
        cout << "invalide chanel selection";
    }
}