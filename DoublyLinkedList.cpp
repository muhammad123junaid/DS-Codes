#include <iostream>
using namespace std;
class Node
{
    int data;
    Node *next;
    Node *prev;

public:
    Node(int val = 0);
    int getData();
    Node *getNext();
    Node *getPrev();
    void setNext(Node *n);
    void setPrev(Node *n);
};
class List
{
    Node *head;
    Node *tail;

public:
    List();
    ~List();
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
    void push_back(int val);
    void pop_back();
    void display();
};
Node::Node(int val) : data(val), next(nullptr),prev(nullptr) {}
int Node::getData()
{
    return data;
}
Node *Node::getNext()
{
    return next;
}
void Node ::setNext(Node *n)
{
    next = n;
}
Node *Node::getPrev()
{
    return prev;
}
void Node ::setPrev(Node *n)
{
    prev = n;
}

List::List()
{
    head = tail = nullptr;
}
Node *List::getHead()
{
    return head;
}
Node *List::getTail()
{
    return tail;
}
void List::setHead(Node *h)
{
    head = h;
}
void List::setTail(Node *t)
{
    tail = t;
}
bool List::isEmpty()
{
    return head == nullptr;
}
int List::size()
{
    int size = 0;
    if (isEmpty())
    {
        return size;
    }
    Node *temp = head;
    while (temp != nullptr)
    {
        size++;
        temp = temp->getNext();
    }
    return size;
}

int List::count(int val)
{
    int count = 0;
    if (isEmpty())
    {
        return count;
    }
    Node *temp = head;
    while (temp != nullptr)
    {
        if (temp->getData() == val)
        {
            count++;
        }
        temp = temp->getNext();
    }
    return count;
}
int List::getFront()
{
    if (isEmpty())
    {
        cout << "List is empty" << endl;
        return -1;
    }
    else
    {
        return head->getData();
    }
}
int List::getBack()
{
    if (isEmpty())
    {
        cout << "List is empty" << endl;
        return -1;
    }
    else
    {
        return tail->getData();
    }
}

void List::display()
{
    if (head == nullptr)
    {
        cout << "List is empty" << endl;
        return;
    }
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->getData() << " ";
        temp = temp->getNext();
    }
}

void List::push_front(int val)
{
    Node *newNode = new Node(val);
    if (isEmpty())
    {
        head = tail = newNode;
    }
    else
    {
        newNode->setNext(head);
        head->setPrev(newNode);
        head = newNode;
    }
}
void List::pop_front()
{
    if (!isEmpty())
        {
            if (head->getNext() == nullptr)
            {
                delete head;
                head = tail = nullptr;
                return;
            }
            Node *temp = head;
            head = head->getNext();
            head->setPrev(nullptr);
            temp->setNext(nullptr);
            delete temp;
        }
        else
        {
            cout << "List is Empty";
            return;
        }
    }
void List::push_back(int val)
{
    Node *newNode = new Node(val);
    if (isEmpty())
    {
        head = tail = newNode;
    }
    else
    {
        newNode->setPrev(tail);
        tail->setNext(newNode);
        tail = newNode;
    }
}
void List::pop_back()
{
    if (!isEmpty())
        {
            if (tail->getPrev() == nullptr)
            {
                delete tail;
                head = tail = nullptr;
                return;
            }
            Node *temp = tail;
            tail = tail->getPrev();
            tail->setNext(nullptr);
            temp->setPrev(nullptr);
            delete temp;
            temp=nullptr;
        }
        else
        {
            cout << "List is Empty";
            return;
        }
    }
List::~List()
{
    if (head == nullptr)
    {
        return;
    }
    Node *temp = head;
    Node *nextNode;

    while (temp != nullptr)
    {
        nextNode = temp->getNext();
        delete temp;
        temp = nextNode;
    }
    head = tail = nullptr;
}
