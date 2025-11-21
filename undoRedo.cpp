#include <iostream>
#include <stack>
using namespace std;

void display(stack<string> s)
{
    while (!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }
    cout << "-----------------------------------\n";
}
void undo(stack<string> &s1, stack<string> &s2)
{
    if (!s1.empty())
    {
        s2.push(s1.top());
        s1.pop();
    }
    display(s1);
}
void redo(stack<string> &s1, stack<string> &s2)
{
    if (!s2.empty())
    {
        s1.push(s2.top());
        s2.pop();
    }
    display(s1);
}
int main()
{
    stack<string> s1;
    stack<string> s2;
    cout << "Enter Name,Email and Password : ";
    for (int i = 0; i < 3; i++)
    {
        string a;
        cin >> a;
        s1.push(a);
    }
    cout << "-----------------------------\n";
    display(s1);
    char ch;
    cout << "Enter 'z' for Undo and 'y' for Redo\n";
    while (cin >> ch)
    {
        if (ch == 'z')
        {
            undo(s1, s2);
        }
        else if (ch == 'y')
        {
            redo(s1, s2);
        }
        else
        {
            cout << "Invalid character, Enter again : ";
        }
    }
    return 0;
}
