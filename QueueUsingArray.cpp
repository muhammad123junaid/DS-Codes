#include <iostream>
using namespace std;
class Queue
{
    int *arr;
    int currSize;
    int capacity;
    int front;
    int rear;

public:
    Queue(int s)
    {
        capacity = s;
        arr = new int[capacity];
        currSize = 0;
        front = 0;
        rear = -1;
    }
    int Size()
    {
        return currSize;
    }
    bool isEmpty()
    {
        return currSize == 0;
    }
    void push(int val)
    {
        if (currSize == capacity)
        {
            cout << "Queue is Full\n";
            return;
        }
        if (rear + 1 == capacity)
        {
            rear = 0;
            arr[rear] = val;
            currSize++;
        }
        else
        {
            ++rear;
            arr[rear] = val;
            currSize++;
        }
    }
    void pop()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty\n";
            return;
        }
        if (front + 1 == capacity)
        {
            front = 0;
            currSize--;
        }
        else
        {
            ++front;
            currSize--;
        }
    }
    int frontVal()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty\n";
            return -1;
        }
        return arr[front];
    }
    int rearVal()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty\n";
            return -1;
        }
        return arr[rear];
    }
    void display()
    {
        int ind = front;
        for (int i = 0; i < currSize; i++)
        {
            cout << arr[ind] << " ";
            ind = (ind + 1) % capacity;
        }
        cout << endl;
    }
};
int main()
{
    Queue q1(4);
    q1.push(6);
    q1.push(8);
    q1.push(23);
    q1.push(5);
    q1.pop();
    q1.push(21);
    q1.display();
    cout << q1.frontVal() << endl;
    cout << q1.rearVal() << endl;
    return 0;
}
