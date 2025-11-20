#include <iostream>
#include "SinglyCircular.h"
using namespace std;

Node::Node(int val)
{
    data = val;
}
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
    else
    {
        Node *temp = head;
        do
        {
            temp = temp->getNext();
            size++;
        } while (temp != head);
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
    else
    {
        Node *temp = head;
        do
        {
            if (temp->getData() == val)
            {
                count++;
            }
            temp = temp->getNext();
        } while (temp != head);
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
    else
    {
        Node *temp = head;
        do
        {
            cout << temp->getData() << " ";
            temp = temp->getNext();
        } while (temp != head);
    }
}

void List::push_front(int val)
{
    Node *newNode = new Node(val);
    if (head == nullptr)
    {
        head = tail = newNode;
        tail->setNext(head);
    }
    else
    {
        tail->setNext(newNode);
        newNode->setNext(head);
        head = newNode;
    }
}
void List::pop_front()
{
    if (head == nullptr)
    {
        return;
    }
    else if (head->getNext() == head)
    {
        delete head;
        head = tail = nullptr;
    }
    else
    {
        Node *temp = head;
        head = head->getNext();
        tail->setNext(head);
        delete temp;
    }
}

List::~List()
{
    if (head == nullptr)
        return;
    Node *start = head;
    Node *temp = head;
    Node *nextNode;

    do
    {
        nextNode = temp->getNext();
        delete temp;
        temp = nextNode;
    } while (temp != start);

    head = tail = nullptr;
}
