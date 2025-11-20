#include <iostream>
using namespace std;
class Node
{
private:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = nullptr;
    }
    friend class List;
};

class List
{
    Node *head;
    Node *tail;

public:
    List()
    {
        head = nullptr;
        tail = nullptr;
    }
    void push_front(int val) // O(1)
    {
        Node *newNode = new Node(val);
        if (head == nullptr)
        {
            head = tail = newNode;
            return;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }

    void push_back(int val) // O(1)
    {
        Node *newNode = new Node(val);
        if (head == nullptr)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop_front() // O(1)
    {
        if (head != nullptr)
        {
            Node *temp = head;
            head = head->next;
            temp->next = nullptr;
            delete temp;
        }
        else
        {
            cout << "List is Empty" << endl;
        }
    }

    void pop_back() // O(n)
    {
        if (head == nullptr)
        {
            cout << "List is empty" << endl;
            return;
        }
        else
        {
            Node *temp = head;
            while (temp->next != tail)
            {
                temp = temp->next;
            }
            temp->next = nullptr;
            delete tail;
            tail = temp;
            temp->next = nullptr;
        }
    }

    void insert(int val, int ind) // O(n)
    {
        int len = 0;
        Node *tempLen = head;
        while (tempLen != nullptr)
        {
            len++;
            tempLen = tempLen->next;
            // cout<<"Length is : "<<len<<endl;
        }
        if (ind < 0)
        {
            cout << "Invalid Index" << endl;
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
        else if (ind > len)
        {
            cout << "Index out of range" << endl;
            return;
        }
        else
        {
            Node *temp = head;
            for (int i = 0; i < ind - 1; i++)
            {
                temp = temp->next;
            }
            Node *newNode = new Node(val);
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    void remove(int index)
    {
        if (head == nullptr)
        {
            cout << "List is empty" << endl;
            return;
        }
        if (index == 0)
        {
            pop_front();
            return;
        }
        if (index < 0)
        {
            cout << "Invalid Index" << endl;
            return;
        }
        Node *temp = head;
        for (int i = 0; temp != nullptr && i < index - 1; i++)
        {
            temp = temp->next;
        }
        if (temp == nullptr || temp->next == nullptr)
        {
            cout << "Invalid index" << endl;
            return;
        }
        Node *del = temp->next;
        temp->next = temp->next->next;
        delete del;
    }
    void removeAll(int val)
    {
        if (head == nullptr)
        {
            cout << "List is empty" << endl;
            return;
        }

        while (head != nullptr && head->data == val)
        {
            pop_front();
        }

        if (head == nullptr)
            return;

        Node *curr = head;

        while (curr->next != nullptr)
        {
            if (curr->next->data == val)
            {
                Node *toDel = curr->next;
                curr->next = curr->next->next;
                delete toDel;
            }
            else
            {
                curr = curr->next;
            }
        }
    }

    void search(int val) // O(n)
    {
        Node *temp = head;
        int index = 0;
        while (temp != nullptr)
        {
            if (temp->data == val)
            {
                cout << val << " is present at index " << index << endl;
            }
            index++;
            temp = temp->next;
        }
    }

    // Sorting
    void sort()
    {
        if (head == nullptr || head->next == nullptr)
        {
            return;
        }
        for (Node *prev = head; prev->next != nullptr; prev = prev->next)
        {
            for (Node *curr = prev->next; curr != nullptr;)
            {
                if (prev->data <= curr->data)
                {
                    curr = curr->next;
                }
                else
                {
                    int temp = prev->data;
                    prev->data = curr->data;
                    curr->data = temp;
                    curr = curr->next;
                }
            }
        }
    }
    void display() // O(n)
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << "\t";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main()
{
    List L1;
    L1.push_front(2);
    L1.display();
    L1.push_front(7);
    L1.display();
    L1.push_front(5);
    L1.display();
    L1.push_back(3);
    L1.push_back(3);
    L1.display();
    L1.push_back(7);
    L1.display();
    // L1.pop_front();
    // L1.display();
    // L1.pop_back();
    // L1.display();
    // L1.insert(12, 1);
    // L1.insert(99, 4);
    // L1.display();
    // L1.removeAll(7);
    L1.sort();
    L1.display();
    // L1.search(12);
    // L1.search(3);
    return 0;
}
