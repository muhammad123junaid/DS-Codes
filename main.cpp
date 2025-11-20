#include <iostream>
#include "SinglyCircular.h"
using namespace std;
int main()
{
    List L1;
    L1.push_front(1);
    L1.push_front(3);
    L1.push_front(7);
    L1.push_front(9);
    L1.pop_front();
    L1.display();
    return 0;
}

// g++ main.cpp SinglyCircular.cpp -o main.exe
// ./main.exe