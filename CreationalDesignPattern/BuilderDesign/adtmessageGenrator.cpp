
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
        virtual void reset()=0;
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

        ConcreateADTmessageBuilder() : message(nullptr) {}

        void reset(){
            if (message != nullptr) {
            delete message;
            }
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
        builder->reset();
        builder->buildMsh();
        builder->buildPv1();
        builder->buildEvn();
        builder->buildPid();
        builder->buildPv2();
    }
    void constructMessage(){
        builder->reset();
        builder->buildMsh();
        builder->buildPv1();
    }
};

int main(){
    // ConcreateADTmessageBuilder* builder = new ConcreateADTmessageBuilder();

    // ADTmessageDirector* director = new ADTmessageDirector(builder);
    // director->constructFullMessage();
    //  cout << "For full message" << endl;
    // ADTmessase* message = builder->getMessage();
    // cout<<message->msh<<endl;
    // cout<<message->pv1<<endl;
    // cout<<message->evn<<endl;
    // cout<<message->pid<<endl;
    // cout<<message->pv2<<endl;


    // // for full message
    // cout << "For partial message" << endl;
    // ConcreateADTmessageBuilder* builder2 = new ConcreateADTmessageBuilder();
    // ADTmessageDirector* director2 = new ADTmessageDirector(builder2);
    // director2->constructMessage();
    // ADTmessase* message2 = builder2->getMessage();
    // cout<<message2->msh<<endl;
    // cout<<message2->pv1<<endl;
    // cout<<message2->evn<<endl;
    // cout<<message2->pid<<endl;
    // cout<<message2->pv2<<endl;






    // alternative using same builder

    ConcreateADTmessageBuilder builder;

    ADTmessageDirector director(&builder);
    director.constructFullMessage();
    ADTmessase* message = builder.getMessage();
    cout<<message->msh<<endl;
    cout<<message->pv1<<endl;
    cout<<message->evn<<endl;
    cout<<message->pid<<endl;
    cout<<message->pv2<<endl;   

    director.constructMessage();
    message = builder.getMessage();
    cout<<message->msh<<endl;
    cout<<message->pv1<<endl;

    return 0;
}
