#include <iostream>
#include<vector>
using namespace std;

class User{
    private:
        string Name;
        string Id;
    public:
        User(string name, string id) : Name(name), Id(id) {}
        const string& getName() const {
            return Name;
        }

};

// Iterator interface
class Iterator{
    public:
        virtual bool hasNext() = 0;
        virtual User *first() = 0;
        virtual User *next() = 0;
        virtual ~Iterator() {}
};
class UserIterator: public Iterator{
    private:
        vector<User*> userList;
        int index;
    public:
        UserIterator(vector<User*> userList) : userList(userList), index(0) {}
        bool hasNext() override {
            return index < userList.size();
        }
        User *first() override {
            return userList[0];
        }
        User *next() override {
            return userList[index++];
        }
};

class UserManagemnt
{
private:
    vector<User*>userList;

public:
    void addUser(User *user)
    {
        userList.push_back(user);
    }
    Iterator* createIterator() {
        return new UserIterator(userList);
    }
};

int main()
{
    UserManagemnt *userManagemnt = new UserManagemnt();

    userManagemnt->addUser(new User("user1", "123"));
    userManagemnt->addUser(new User("user2", "456"));
    userManagemnt->addUser(new User("user3", "789"));

    Iterator *iterator = userManagemnt->createIterator();

    while (iterator->hasNext()) {
        User *user = iterator->next();
        cout << user->getName() << endl;
    }

    return 0;
}