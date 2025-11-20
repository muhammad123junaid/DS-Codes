#include <iostream>
using namespace std;
class Node
{
    int data;
    Node *next;
    Node *prev;

public:
    Node(int val)
    {
        data = val;
        next = prev = nullptr;
    }
    friend class DoublyList;
};

class DoublyList
{
    Node *head;
    Node *tail;

public:
    DoublyList()
    {
        head = tail = nullptr;
    }
    void push_front(int val)
    {
        Node *new_node = new Node(val);
        if (head == nullptr)
        {
            head = tail = new_node;
        }
        else
        {
            new_node->next = head;
            head->prev = new_node;
            head = new_node;
        }
    }
    void pop_front()
    {
        if (head != nullptr)
        {
            if (head->next == nullptr)
            {
                delete head;
                head = tail = nullptr;
                return;
            }
            Node *temp = head;
            head = head->next;
            head->prev = nullptr;
            temp->next = nullptr;
            delete temp;
        }
        else
        {
            cout << "List is Empty";
            return;
        }
    }

    void push_back(int val)
    {
        Node *new_node = new Node(val);
        if (head == nullptr)
        {
            head = tail = new_node;
        }
        else
        {
            new_node->prev = tail;
            tail->next = new_node;
            tail = new_node;
        }
    }

    void pop_back()
    {
        if (tail != nullptr)
        {
            if (tail->prev == nullptr)
            {
                delete tail;
                head = tail = nullptr;
                return;
            }
            Node *temp = tail;
            tail = tail->prev;
            tail->next = nullptr;
            temp->prev = nullptr;
            delete temp;
        }
        else
        {
            cout << "List is Empty";
            return;
        }
    }

    void insert(int val, int ind)
    {
        Node *new_node = new Node(val);
        Node *temp = head;
        for (int i = 0; i < ind - 1; i++)
        {
            temp = temp->next;
        }
        new_node->prev = temp;
        temp->next->prev = new_node;
        new_node->next = temp->next;
        temp->next = new_node;
    }

    void erase(int val)
    {
        int count =0;
        Node *curr = head;
        while (curr != nullptr)
        {
            if (curr->data == val)
            {
                count++;
                if (curr->prev == nullptr)
                {
                    pop_front();
                    curr=head;
                }
                else if (curr->next == nullptr)
                {
                    pop_back();
                    curr=nullptr;
                }
                else
                {
                    Node *to_del = curr;
                    Node *nextNode = curr->next;
                    curr->prev->next = curr->next;
                    curr->next->prev = curr->prev;
                    to_del->prev = nullptr;
                    to_del->next = nullptr;
                    delete to_del;
                    curr = nextNode;
                }
            }
            else
            {
                curr = curr->next;
            }
        }
        cout<<"Count is : "<<count<<endl;
    }
    void display()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " <--> ";
            temp = temp->next;
        }
        cout << "nullptr\n\n";
    }

    void reverseDisplay()
    {
        Node *temp = tail;
        while (temp != nullptr)
        {
            cout << temp->data << " <--> ";
            temp = temp->prev;
        }
        cout << "nullptr\n\n";
    }
};
int main()
{
    DoublyList D1;
    D1.push_front(1);
    D1.push_front(3);
    D1.push_front(4);
    D1.push_front(3);
    D1.push_front(7);
    D1.push_back(9);
    D1.push_back(15);
    D1.insert(44, 3);
    D1.display();
    D1.reverseDisplay();
    D1.pop_front();
    D1.pop_back();
    D1.display();
    D1.erase(3);
    D1.display();
    return 0;
}