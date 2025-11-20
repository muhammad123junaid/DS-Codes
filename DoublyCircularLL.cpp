#include <iostream>
using namespace std;
class Node
{
    int data;
    Node *prev;
    Node *next;

public:
    Node(int val)
    {
        data = val;
        prev = next = nullptr;
    }
    friend class CircularList;
};

class CircularList
{
    Node *head = nullptr;
    Node *tail = nullptr;

public:
    CircularList()
    {
        head = tail = nullptr;
    }
    void push_front(int val)
    {
        Node *new_node = new Node(val);
        if (head == nullptr)
        {
            head = tail = new_node;
            head->prev = head;
            head->next = head;
        }
        else
        {
            new_node->next = head;
            new_node->prev = tail;
            head->prev = new_node;
            tail->next = new_node;
            head = new_node;
        }
    }

    void pop_front()
    {
        if (head == nullptr)
        {
            cout << "List is Empty\n";
        }
        else if (head->next == head)
        {
            delete head;
            head = tail = nullptr;
        }
        else
        {
            Node *curr = head;
            head = head->next;
            tail->next = head;
            head->prev = tail;
            delete curr;
        }
    }

    void push_back(int val)
    {
        Node *new_Node = new Node(val);
        if (head == nullptr)
        {
            head = tail = new_Node;
            head->prev = head;
            head->next = head;
        }
        else
        {
            tail->next = new_Node;
            new_Node->prev = tail;
            new_Node->next = head;
            head->prev = new_Node;
            tail = new_Node;
        }
    }

    void pop_back()
    {
        if (head == nullptr)
        {
            cout << "List is Empty\n";
            return;
        }
        else if (head->next == head)
        {
            delete head;
            head = tail = nullptr;
        }
        else
        {
            Node *temp = tail;
            tail = tail->prev;
            tail->next = head;
            head->prev = tail;
            delete temp;
        }
    }

    void insert(int val, int ind)
    {
        int len = 0;
        if (head != nullptr)
        {
            Node *temp = head;
            do
            {
                len++;
                temp = temp->next;
            } while (temp != head);
        }
        if (ind < 0 || ind > len)
        {
            cout << "Invalid Index\n";
            return;
        }
        else if (ind == 0)
        {
            push_front(val);
        }
        else if (ind == len)
        {
            push_back(val);
        }
        else
        {
            Node *new_Node = new Node(val);
            Node *curr = head;
            for (int i = 0; i < ind - 1; i++)
            {
                curr = curr->next;
            }
            new_Node->prev = curr;
            new_Node->next = curr->next;
            curr->next->prev = new_Node;
            curr->next = new_Node;
        }
    }

    void remove(int v)
    {
        if (head == nullptr)
        {
            cout << "List is empty\n";
            return;
        }
        Node *temp = head;
        bool found = false;
        do
        {
            if (temp->data == v)
            {
                found = true;
                if (head == head->next)
                {
                    delete head;
                    head = tail = nullptr;
                    break;
                }
                else if (temp == head)
                {
                    if (head == nullptr)
                    {
                        cout << "List is Empty\n";
                    }
                    else if (head->next == head)
                    {
                        delete head;
                        head = tail = nullptr;
                    }
                    else
                    {
                        Node *curr = head;
                        head = head->next;
                        tail->next = head;
                        head->prev = tail;
                        delete curr;
                        temp = head;
                        continue;
                    }
                }
                else if (temp == tail)
                {
                    pop_back();
                    temp = head;
                }
                else
                {
                    Node *to_del = temp;
                    Node *nextNode = temp->next;
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                    delete to_del;
                    temp = nextNode;
                }
            }
            else
            {
                temp = temp->next;
            }
        } while (temp != head);
        if (!found)
        {
            cout << "Value not found\n";
        }
    }
    void display()
    {
        if (head == nullptr)
        {
            cout << "List is empty." << endl;
            return;
        }
        Node *temp = head;
        do
        {
            cout << temp->data << "\t";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};
int main()
{
    CircularList CL1;
    CL1.push_front(4);
    CL1.push_front(9);
    CL1.push_front(4);
    CL1.push_front(5);
    CL1.push_front(3);
    CL1.push_front(12);
    CL1.push_back(88);
    CL1.insert(4, 4);
    CL1.pop_front();
    CL1.pop_back();
    CL1.display();
    CL1.remove(4);
    CL1.display();
    return 0;
}