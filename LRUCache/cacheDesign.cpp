// LRU cache means if size of chache is full then remove least recent use node
// when getnode then it should be come first - Recently used

// using double linked list

#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

class Node{
public:
    int key;
    int value;
    Node *next;
    Node *prev;
    Node(int k, int val)
    {
        key = k;
        value = val;
        next = nullptr;
        prev = nullptr;
    }
};
class LRUCache{
    private:
        int capacity;
        unordered_map<int, Node *> cache;
        Node *head = new Node(-1,-1);
        Node *tail = new Node(-1,-1);
        void deleteNode(Node *delNode)
        {
            Node *delprev=delNode->prev;
            Node *delnext=delNode->next;
            delprev->next=delnext;
            delnext->prev=delprev;
        }
        void addNode(Node *newNode)
        {
            Node *temp=head->next;
            newNode->next=temp;
            newNode->prev=head;
            head->next=newNode;
            temp->prev=newNode;
        }
    public:
        LRUCache(int cap)
        {
            capacity = cap;
            head->next = tail;
            tail->prev = head;
        }
      
        int get(int key)
        {
            if(cache.find(key)!=cache.end())
            {
                Node *node=cache[key];
                int res = node->value;
                deleteNode(node); // Unlink the node
                addNode(node); // Move the node to the front (most recent)
                cache[key] = node; // Update map to point to the new head
                return res;
            }
            return -1;
        }
        void put(int key, int value)
        {
            // if key is already find in cache
            if(cache.find(key)!=cache.end())
            {
                Node *node=cache[key]; 
                cache.erase(key);  // delete from cache 
                deleteNode(node); // Unlink the node
                delete node;
            }
            /// if size of cache is full need to delete last node
            cout << cache.size()<< "="<<capacity<< endl;
            if (cache.size() == capacity)
            {
                Node *delNode = tail->prev;
                cache.erase(delNode->key);
                deleteNode(delNode);
                delete delNode;
            }

            Node *newNode = new Node(key, value);
            addNode(newNode);
            cache[key] = newNode;
        }
         // Destructor to free allocated memory
        ~LRUCache() {
            Node* current = head;
            while (current) {
                Node* next = current->next;
                delete current;
                current = next;
            }
        }
};
//1-3-2
int main()
{
    LRUCache cache(3);
    cache.put(1, 10);
    cache.put(2, 20);
    cache.put(3, 30);
    cout << "Get(1): " << cache.get(1) << endl;  // Output: 10

    cache.put(4, 40); // Evicts key 2 (Least Recently Used)
    cout << "Get(2): " << cache.get(2) << endl;  // Output: -1 (not found)

    cache.put(5, 50); // Evicts key 3
    cout << "Get(3): " << cache.get(3) << endl;  // Output: -1 (not found)
    cout << "Get(4): " << cache.get(4) << endl;  // Output: 40
    cout << "Get(5): " << cache.get(5) << endl;  // Output: 50  
}