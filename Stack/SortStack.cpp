#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void insert(stack<int> &s, int &target)
{
    if (s.empty() || s.top() >= target)
    {
        s.push(target);
        return;
    }

    int temp = s.top();
    s.pop();
    insert(s, target);
    // backTracking
    s.push(temp);
}

void Sort(stack<int> &s)
{
    if (s.empty())
        return;

    int temp = s.top();
    s.pop();
    Sort(s);

    insert(s,temp);
}

int main(){
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(3);
    s.push(6);
    s.push(2);
    s.push(9);
    s.push(4);
    s.push(5);
    s.push(2);

    Sort(s);

    while(!s.empty())
    {
        cout<<s.top()<<endl;
        s.pop();
    }
    return 0;
}