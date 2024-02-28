#include<bits/stdc++.h>
using namespace std;


class shape{
public:
    virtual void draw();
};

class rect : public shape{
    void draw() override{
        cout << "from rectngle class" << endl;
    }
};

class circle : public shape{
    void draw() override{
        cout << " from circle class" << endl;
    }
};

int main()
{
    cout << "lucky" << endl;
}
