#include<iostream>
using namespace std;

class OrderProcessingTemplate
{
    public:
    void processing()
    {
        verifyOrder();
        assignDelivery();
        trackOrder(); 
    }
    virtual void verifyOrder()=0;
    virtual void assignDelivery()=0;
    virtual void trackOrder()=0;
    ~OrderProcessingTemplate(){}
};

class LocalOrderProcess: public OrderProcessingTemplate
{
    public:
    void verifyOrder()
    {
        cout<<"Verify order locally"<<endl;
    }
    void assignDelivery()
    {
        cout<<"Assign delivery locally"<<endl;
    }
    void trackOrder()
    {
        cout<<"Track order locally"<<endl;
    }
};

class InternationalOrderProcess: public OrderProcessingTemplate
{
    public:
    void verifyOrder()
    {
        cout<<"Verify order internationally"<<endl;
    }
    void assignDelivery()
    {
        cout<<"Assign delivery internationally"<<endl;
    }
    void trackOrder()
    {
        cout<<"Track order internationally"<<endl;
    }
};


int main()
{
    OrderProcessingTemplate* order = new LocalOrderProcess();
    order->processing();
    

    OrderProcessingTemplate* order1 = new InternationalOrderProcess();
    order1->processing();

    delete order;
    delete order1;
    return 0;
}
