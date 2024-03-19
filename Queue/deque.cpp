#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Deque
{
    int front;
    int back;
    int size;
    int *arr;

public:
    Deque(int _val)
    {
        arr = new int[_val];
        size = _val;
        front = -1;
        back = -1;
    }

    void push_back(int _val)
    {
        if ((front == 0 && back == size - 1) || front == back + 1)
        {
            cout << "Error Overflow" << endl;
            return;
        }
        if (front == -1)
        {
            front = 0;
            back = 0;
        }
        else if (back == size - 1 && front != 0)
            back = 0;
        else
            back++;
        arr[back] = _val;
    }

    void pop_back()
    {
        if (front == -1)
        {
            cout << "Not Possible" << endl;
            return;
        }
        else if (front == back)
        {
            front = -1;
            back = -1;
        }
        else if (back == 0 && front != 0)
        {
            back = size - 1;
        }
        else
            back--;
    }

    void pop_front()
    {
        if (front == -1)
        {
            cout << "Not Possible" << endl;
            return;
        }
        else if (front == back)
        {
            front = -1;
            back = -1;
        }
        else if (front == size - 1 && back != size - 1)
        {
            front = 0;
        }
        else
            front++;
    }

    void push_front(int _val)
    {
        if ((front == 0 && back == size - 1) || front == back + 1)
        {
            cout << "Error Overflow" << endl;
            return;
        }
        if (front == -1)
        {
            front = 0;
            back = 0;
        }
        else if (back != size - 1 && front == 0)
            front = size - 1;
        else
            front--;
        arr[front] = _val;
    }
};

int main()
{

    return 0;
}