#include<iostream>
using namespace std;
#include "NotificationManager.hpp"
int main()
{
    NotificationManager *notificationManager = NotificationManager::getInstance();
    notificationManager->sendNotification("Hello", "email");
    notificationManager->sendNotification("Hello", "SMS");
    return 0;
}