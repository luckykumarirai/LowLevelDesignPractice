#include<iostream>
using namespace std;

//A pure virtual function is a special kind of virtual function in C++ that is declared in a base class but has no implementation
// Classes containing pure virtual functions are called abstract classes, and they cannot be instantiated directly.

class IButton{
    public:
     virtual void press() = 0;

};

//they(IButton) serve as base classes for other classes, which must provide implementations for all pure virtual functions to become concrete classes.
class MacButton : public IButton{
    public:
    void press() override {
        std::cout << "MacButton pressed" << std::endl;
    }
};
class WinButton : public IButton{
    public:
    void press() override {
        std::cout << "MacButton pressed" << std::endl;
    }
};


class ITextBox{
    public:
     virtual void showText() = 0;

};
//they(ITextBox) serve as base classes for other classes, which must provide implementations for all pure virtual functions to become concrete classes.
class MacTextBox : public ITextBox{
    public:
    void showText() override {
        std::cout << "Mac text showTexted" << std::endl;
    }
};
class WinTextBox : public ITextBox{
    public:
    void showText() override {
        std::cout << "Mac text pressed" << std::endl;
    }
};


class IFactory{
    public:
    virtual IButton * CreateButton () = 0;
    virtual ITextBox * CreateTextBox () = 0;
};

class MacFactory : public IFactory{
    public:
        IButton * CreateButton()
        {
            return new MacButton();
        }
        ITextBox* CreateTextBox() {
            return new MacTextBox();
        }
};
class WinFactory : public IFactory{
    public:
        IButton * CreateButton()
        {
            return new WinButton();
        }
        ITextBox* CreateTextBox() {
            return new WinTextBox();
        }
};

class GUIAbstractFactory{
public:
    static IFactory * CreateFactory(string osType)
    {
        IFactory * fact = nullptr;
        if(osType ==" window")
        {
            fact= new WinFactory();
        }
        else if( osType == "Mac")
        {
            fact=new MacFactory();
        }
        return fact;
    }
};




int main()
{
     cout << "Eneter your Machine OS"<<endl;
     string osType;
     cin >>osType;

     IFactory *fact = GUIAbstractFactory:: CreateFactory(osType);

     IButton *button  = fact ->CreateButton();
     button -> press();

     ITextBox * textbox = fact ->CreateTextBox();
     textbox->showText();
;     return 0;
}