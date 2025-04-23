
#include<iostream>
using namespace std;

// Product that we want to build
class ADTmessase{
    public:
        string msh;
        string pv1;
        string evn;
        string pid;
        string pv2;
};

// interface builder 

class ADTmessageBuilder{
    public:
        virtual void buildMsh()=0;
        virtual void buildPv1()=0;
        virtual void buildEvn()=0;
        virtual void buildPid()=0;
        virtual void buildPv2()=0;
        virtual ADTmessase* getMessage()=0;
};          

// concreate builder for interface 

class ConcreateADTmessageBuilder : public ADTmessageBuilder{
    public:
        ADTmessase* message;
        ConcreateADTmessageBuilder(){
            message = new ADTmessase();
        }
        void buildMsh(){
            message->msh = "MSH|";
        }
        void buildPv1(){
            message->pv1 = "PV1|";
        }
        void buildEvn(){
            message->evn = "EVN|";
        }
        void buildPid(){
            message->pid = "PID|";
        }
        void buildPv2(){
            message->pv2 = "PV2|";
        }
        ADTmessase* getMessage(){
            return message;
        }
};

// director class

class ADTmessageDirector{
    public: 
    ADTmessageBuilder* builder;
    ADTmessageDirector(ADTmessageBuilder* builder) : builder(builder) {}    
    void constructFullMessage(){
        builder->buildMsh();
        builder->buildPv1();
        builder->buildEvn();
        builder->buildPid();
        builder->buildPv2();
    }
    void constructMessage(){
        builder->buildMsh();
        builder->buildPv1();
    }
};

int main(){
    ConcreateADTmessageBuilder* builder = new ConcreateADTmessageBuilder();

    ADTmessageDirector* director = new ADTmessageDirector(builder);
    director->constructMessage();

    ADTmessase* message = builder->getMessage();
    cout<<message->msh<<endl;
    cout<<message->pv1<<endl;
    cout<<message->evn<<endl;
    cout<<message->pid<<endl;
    cout<<message->pv2<<endl;


    // for full message

    director->constructFullMessage();
    message = builder->getMessage();
    cout<<message->msh<<endl;
    cout<<message->pv1<<endl;
    cout<<message->evn<<endl;
    cout<<message->pid<<endl;
    cout<<message->pv2<<endl;
    return 0;
}
