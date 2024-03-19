#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void Middle(stack<int>& s, int& ActualSize)
{
    if (s.size() == ActualSize/2 + 1)
    {
        cout<<s.top()<<endl;
        return;
    }

    int temp = s.top();
    s.pop();
    Middle(s,ActualSize);
    s.push(temp);
}

int main(){
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    // s.push(6);
    int sz = s.size();
    Middle(s,sz);
    return 0;
}