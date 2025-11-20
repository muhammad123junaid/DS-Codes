class Node
{
    int data;
    Node *next;

public:
    Node(int val);
    int getData();
    Node *getNext();
    void setNext(Node *n);
};
class List
{
    Node *head;
    Node *tail;

public:
    List();
    bool isEmpty();
    int size();
    int count(int val);
    int getFront();
    int getBack();
    Node *getHead();
    Node *getTail();
    void setHead(Node *h);
    void setTail(Node *t);
    void push_front(int val);
    void pop_front();
    void display();

};
