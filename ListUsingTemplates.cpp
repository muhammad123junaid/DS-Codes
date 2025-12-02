#include <iostream>
using namespace std;

template <typename T>
class Node
{
    T data;
    Node<T> *next;

public:
    Node(T val = 0);
    T getData();
    Node<T> *getNext();
    void setNext(Node<T> *n);
};

template <typename T>
class List
{
    Node<T> *head;
    Node<T> *tail;

public:
    List();
    ~List();
    bool isEmpty();
    int size();
    int count(T val);
    T getFront();
    T getBack();
    Node<T> *getHead();
    Node<T> *getTail();
    void setHead(Node<T> *h);
    void setTail(Node<T> *t);
    void push_front(T val);
    void pop_front();
    void push_back(T val);
    void pop_back();
    void display();
};

template <typename T>
Node<T>::Node(T val) : data(val), next(nullptr) {}

template <typename T>
T Node<T>::getData()
{
    return data;
}

template <typename T>
Node<T> *Node<T>::getNext()
{
    return next;
}

template <typename T>
void Node<T>::setNext(Node<T> *n)
{
    next = n;
}

template <typename T>
List<T>::List()
{
    head = tail = nullptr;
}

template <typename T>
Node<T> *List<T>::getHead()
{
    return head;
}

template <typename T>
Node<T> *List<T>::getTail()
{
    return tail;
}

template <typename T>
void List<T>::setHead(Node<T> *h)
{
    head = h;
}

template <typename T>
void List<T>::setTail(Node<T> *t)
{
    tail = t;
}

template <typename T>
bool List<T>::isEmpty()
{
    return head == nullptr;
}

template <typename T>
int List<T>::size()
{
    int size = 0;
    if (isEmpty())
    {
        return size;
    }
    Node<T> *temp = head;
    while (temp != nullptr)
    {
        size++;
        temp = temp->getNext();
    }
    return size;
}

template <typename T>
int List<T>::count(T val)
{
    int count = 0;
    if (isEmpty())
    {
        return count;
    }
    Node<T> *temp = head;
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

template <typename T>
T List<T>::getFront()
{
    if (isEmpty())
    {
        cout << "List is empty" << endl;
        return T();
    }
    else
    {
        return head->getData();
    }
}

template <typename T>
T List<T>::getBack()
{
    if (isEmpty())
    {
        cout << "List is empty" << endl;
        return T();
    }
    else
    {
        return tail->getData();
    }
}

template <typename T>
void List<T>::display()
{
    if (head == nullptr)
    {
        cout << "List is empty" << endl;
        return;
    }
    Node<T> *temp = head;
    while (temp != nullptr)
    {
        cout << temp->getData() << " ";
        temp = temp->getNext();
    }
}

template <typename T>
void List<T>::push_front(T val)
{
    Node<T> *newNode = new Node<T>(val);
    if (isEmpty())
    {
        head = tail = newNode;
    }
    else
    {
        newNode->setNext(head);
        head = newNode;
    }
}

template <typename T>
void List<T>::pop_front()
{
    if (isEmpty())
    {
        return;
    }
    else
    {
        Node<T> *temp = head;
        head = head->getNext();
        delete temp;
    }
}

template <typename T>
void List<T>::push_back(T val)
{
    Node<T> *newNode = new Node<T>(val);
    if (isEmpty())
    {
        head = tail = newNode;
    }
    else
    {
        tail->setNext(newNode);
        tail = newNode;
    }
}

template <typename T>
void List<T>::pop_back()
{
    if (isEmpty())
    {
        cout << "List is Empty\n";
        return;
    }
    else if (head == tail)
    {
        delete head;
        head = tail = nullptr;
        return;
    }
    else
    {
        Node<T> *temp = head;
        while (temp->getNext() != tail)
        {
            temp = temp->getNext();
        }
        delete tail;
        tail = temp;
        tail->setNext(nullptr);
    }
}

template <typename T>
List<T>::~List()
{
    if (head == nullptr)
    {
        return;
    }
    Node<T> *temp = head;
    Node<T> *nextNode;

    while (temp != nullptr)
    {
        nextNode = temp->getNext();
        delete temp;
        temp = nextNode;
    }
    head = tail = nullptr;
}

int main()
{
    List<int> L1;
    L1.push_back(7);
    L1.push_back(9);
    L1.push_front(12);
    L1.push_front(53);
    L1.display();
    return 0;
}
