#include<iostream>
using namespace std;
// singlton means create a object only once so think to how we can resist to calling constructor 
#include <mutex>

class Samosa
{
private:
    static Samosa *samosaInstance ;
    Samosa(){
        cout << "constructor created for samosa class\n";
    };

public:
    static Samosa * getSamosa() {
        if(samosaInstance == nullptr)
        {
            
            samosaInstance = new Samosa();
        }
        return samosaInstance;
    };
};
Samosa *Samosa::samosaInstance = nullptr;

