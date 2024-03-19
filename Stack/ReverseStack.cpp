#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void insertBottom(stack<int>& s, int &target)
{
    if (s.empty())
    {
        s.push(target);
        return;
    }

    int temp = s.top();
    s.pop();
    insertBottom(s,target);
    s.push(temp);
}

void reverse(stack<int>&s)
{
    if (s.empty())
    {
        return;
    }

    int temp = s.top();
    s.pop();

    reverse(s);

    insertBottom(s, temp);
}

void print(stack<int>&s)
{
    if (s.empty())
        return;

    int temp = s.top();
    s.pop();
    print(s);
    s.push(temp);
    cout<<s.top()<<endl;
}

int main(){
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);

    print(s);
    cout<<endl;

   reverse(s);

    print(s);
    return 0;
}