#include <iostream>
using namespace std;
class Stack
{
    int *arr;
    int capacity;
    int currSize;
    int top;

public:
    Stack(int s)
    {
        capacity = s;
        arr = new int[capacity];
        currSize = 0;
        top = -1;
    }
    bool isEmpty()
    {
        return currSize == 0;
    }
    void push(int val)
    {
        if (currSize == capacity)
        {
            int newCap = capacity * 2;
            int *newArr = new int[newCap];
            for (int i = 0; i < currSize; i++)
            {
                newArr[i] = arr[i];
            }
            delete[] arr;
            arr = newArr;
            capacity = newCap;
        }
        ++top;
        arr[top] = val;
        currSize++;
    }
    void pop()
    {
        if (isEmpty())
        {
            return;
        }
        --top;
        currSize--;
    }
    int topVal()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty\n";
            return -1;
        }
        return arr[top];
    }
    void display()
    {
        int ind = top;
        for (int i = 0; i < currSize; i++)
        {
            cout << arr[ind] << " ";
            ind--;
        }
        cout << endl;
    }
    ~Stack(){
        delete [] arr;
    }
};
int main()
{
    Stack s1(3);
    s1.push(23);
    s1.push(3);
    s1.push(2);
    s1.pop();
    s1.push(5);
    s1.push(25);
    s1.display();
    cout << s1.topVal() << endl;
    return 0;
}