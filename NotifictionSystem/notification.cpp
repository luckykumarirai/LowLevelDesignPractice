#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

//------------------------------------------------------------------------------
//                           INotification                 
//------------------------------------------------------------------------------


//abstact class - pure vitual so it is an interface
class INotification{
    public:
        virtual string getContent() const=0;
        virtual ~INotification(){};
};
// concreate notification - simple text notification
class SimpleNotification: public INotification
{
    private :
        string message;
    public:
        SimpleNotification(const string &msg): message(msg){};
        string getContent()const override
        {
            return message;
        }
};
class AdvanceNotification: public INotification
{
    private :
        string message;
    public:
        AdvanceNotification(const string &msg): message(msg){};
        string getContent()const override
        {
            return message;
        }
};


//------------------------------------------------------------------------------
//                           INotificationDecorator ----Decortion Desing Pattern                
//---------------------------------------------------------------------------------
// inheritance - INotification interface === is a 
// Conatin INotification - Has a relationship
class INotificationDecorator: public INotification{
    public:
        INotification *notification;
        INotificationDecorator(INotification *n)
        {
            notification=n;
        }
        virtual ~INotificationDecorator()
        {
            delete notification;
        };
};
class Signature: public INotificationDecorator
{
    private:
        string signature;
    public:
      Signature(INotification *n, string sign): INotificationDecorator(n), signature(sign){}
       // Get Notication then add extra signature 
       string getContent()const override
        {
            return notification->getContent()+signature;
        
        }

};
class TimeStamp:public  INotificationDecorator
{
    private:
        string timestamp;
    public:
        TimeStamp(INotification *n, string ts) : INotificationDecorator(n), timestamp(ts){}
        string getContent()const override
        {
            return notification->getContent()+timestamp;
        }
};
//------------------------------------------------------------------------------
//                         IObservable   --- Observer Design Pattern                  
//---------------------------------------------------------------------------------
class Iobservers{
    public: 
        virtual void update()=0;
};

class IObservable{
    public:
    virtual void addObservers(Iobservers *ob) =0;
    virtual void removeObservers(Iobservers *ob) =0;
    virtual void Notify() =0;
    // Pure virtual destructor (with definition in .cpp)
    virtual ~IObservable() = 0;  
};
inline IObservable::~IObservable() {}

class NotificationObservable: public IObservable
{
    public:
        vector<Iobservers*> observerList;             // Observable class has all observers list
        INotification *currentNotification; 
        NotificationObservable()
        {
                currentNotification=nullptr;
        }
       void addObservers(Iobservers *ob) override
       {
            observerList.push_back(ob);
       }
       void removeObservers(Iobservers *ob) override
        {
            observerList.erase(
                std::remove(observerList.begin(), observerList.end(), ob),
                observerList.end()
            );
        }
       void Notify() override
       {
            for(Iobservers *ob: observerList)
            {
                ob->update();
            }
       }
       void setNotification(INotification *n)
       {
            if(currentNotification!=nullptr)
            {
                    delete currentNotification;
            }
            currentNotification=n;
            Notify();
       }
       string getNotificationContent() 
       {
            return currentNotification->getContent();
       }
       INotification *getNotification()
       {
             return currentNotification;  
       }
       ~NotificationObservable()
       {
            currentNotification = nullptr;
       }
};


/*============================
       NotificationService
=============================*/

// The NotificationService manages notifications. It keeps track of notifications. 
// Any client code will interact with this service.

// Singleton class
class NotificationService {
private:
    NotificationObservable* observable;
    static NotificationService* instance;
    vector<INotification*> notifications;

    NotificationService() {
        // private constructor
        observable = new NotificationObservable();
    }

public:
    static NotificationService* getInstance() {
        if(instance == nullptr) {
            instance = new NotificationService();
        }
        return instance;
    }

    // Expose the observable so observers can attach.
    NotificationObservable* getObservable() {
        return observable;
    }

    // Creates a new Notification and notifies observers.
    void sendNotification(INotification* notification) {
        notifications.push_back(notification);
        observable->setNotification(notification);
    }

    ~NotificationService() {
        for (auto n : notifications) {
            delete n;   // ✅ cleanup notifications
        }
    }
};

NotificationService* NotificationService::instance = nullptr;


/*============================
       ConcreteObservers
=============================*/
class Logger : public Iobservers {
private:
    NotificationObservable* notificationObservable;

public:
    Logger() {
       this->notificationObservable = NotificationService::getInstance()->getObservable();
       notificationObservable->addObservers(this);
    }

    Logger(NotificationObservable* observable) {
        this->notificationObservable = observable;
        notificationObservable->addObservers(this);
    }

    void update() {
        cout << "Logging New Notification : \n" << notificationObservable->getNotificationContent()<<endl;
    }
    ~Logger() {
      notificationObservable->removeObservers(this);
    }

};


//------------------------------------------------------------------------------
//                          Notification strategy  --- strategy  Design Pattern                  
//---------------------------------------------------------------------------------
class INotificationStrategy 
{
    public:
        virtual void notify(string  notification) = 0;

};
class SMS: public INotificationStrategy
{
    public:
        void notify(string notification)
        {
            cout <<"This is Notification"<<notification<<"using SMS strategy"<<endl;
        }
};
class Email: public INotificationStrategy
{
    public:
        void notify(string notification)
        {
            cout <<"This is Notification"<<notification<<"using Email strategy"<<endl;
        }
};



class NotificationEngine : public Iobservers {
private:
    NotificationObservable* notificationObservable;
    vector<INotificationStrategy*> notificationStrategies;

public:
    NotificationEngine() {
        this->notificationObservable = NotificationService::getInstance()->getObservable();
        notificationObservable->addObservers(this);
    }

    NotificationEngine(NotificationObservable* observable) {
        this->notificationObservable = observable;
    }

    void addNotificationStrategy(INotificationStrategy* ns) {
        this->notificationStrategies.push_back(ns);
    }

    // Can have RemoveNotificationStrategy as well.

    void update() {
        string notificationContent = notificationObservable->getNotificationContent();
        for(const auto notificationStrategy : notificationStrategies) {
            notificationStrategy->notify(notificationContent);
        }
    }
    ~NotificationEngine() {
        notificationObservable->removeObservers(this);
        for (auto ns : notificationStrategies) {
            delete ns;   // ✅ cleanup strategies
        }
    }

};

int main() {
    // Create NotificationService.
    NotificationService* notificationService = NotificationService::getInstance();
   
    // Create Logger Observer
    Logger* logger = new Logger();

    // Create NotificationEngine observers.
    NotificationEngine* notificationEngine = new NotificationEngine();

    notificationEngine->addNotificationStrategy(new SMS());
    notificationEngine->addNotificationStrategy(new Email());

    // Create a notification with decorators.
    INotification* notification = new SimpleNotification("Your order has been shipped!");
    notification = new TimeStamp(notification, "2025-29-08");
    notification = new Signature(notification, "lucky");
    
    
    notificationService->sendNotification(notification);

    delete logger;
    delete notificationEngine;
    return 0;
}
