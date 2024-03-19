#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// void reverse(queue<int> &q)
// {
//     stack<int> st;
//     while (!q.empty())
//     {
//         st.push(q.front());
//         q.pop();
//     }

//     while(!st.empty())
//     {
//         q.push(st.top());
//         st.pop();
//     }
// }

void reverse(queue<int> &q)
{
    if (q.empty())
        return;

    int temp = q.front();

    q.pop();

    reverse(q);

    q.push(temp);
}

int main()
{
    queue<int> q;
    q.push(3);
    q.push(4);
    q.push(5);

    reverse(q);

    while(!q.empty())
    {
        cout<<q.front()<<endl;
        q.pop();
    }

    return 0;
}