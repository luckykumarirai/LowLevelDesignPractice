#include<iostream>
using namespace std;

//adaptee
class JsonAnalyticTool{
    public:
    void displayJsonData(string data){
        cout<<"Json Data"<<endl;
    }
};

// interface of adapter
class AnalyticTool{
    public:
    virtual void displayJsonData(string data)=0;
};

// concreate adapter
class XmlToJsonAdapter : public AnalyticTool{
    JsonAnalyticTool jsonTool;
    public:
    void displayJsonData(string data){
        jsonTool.displayJsonData(data);
    }
};

int main()
{
    AnalyticTool *adapter = new XmlToJsonAdapter();
    adapter->displayJsonData("xml data");

    return 0;
}
