// it has 3 main charcter 
//1. Invoker - who will call the command
//2. Receiver - who will execute the command
//3.  Lisner   - who will execute the command


#include<iostream>
using namespace std;

// an interface that implement by each concrete Lisner command
 class ILisnerCommand{
    public:
    virtual void execute() = 0;
    virtual ~ILisnerCommand() {}
 };

 // Receiver
 class Document{
   public:
    void open() {
        cout << "Document Opened" << endl;
    }

    void save() {
        cout << "Document Saved" << endl;
    }
 };


 // Concrete Command
class SaveDocument : public ILisnerCommand {
private:
    Document* doc;

public:
    SaveDocument(Document* document) : doc(document) {}

    void execute() {
        doc->save();
    }
};

 // concreate command 
 class OpneDocument : public ILisnerCommand{
    private:
         Document *doc;
    public:
    OpneDocument(Document* document) : doc(document) {}   
    void execute(){
        doc->open();
    }
 };

 class Invoker{
    private:
    ILisnerCommand* command;
    public:
    void setCommand(ILisnerCommand* command){
        this->command = command;
    }
    void call(){
        command->execute();
    }
    
 };

int main(){

    Document *doc = new Document();
    // create an object of conrcrete command
    ILisnerCommand *command = new OpneDocument(doc);

    Invoker *invoker = new Invoker();
    invoker->setCommand(command);
    invoker->call();

    ILisnerCommand *command2 = new SaveDocument(doc);
    invoker->setCommand(command2);
    invoker->call();

    delete doc;
    delete invoker;
    delete command;
    delete command2;

    return 0;

}
