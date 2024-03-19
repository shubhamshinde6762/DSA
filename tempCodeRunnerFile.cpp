#include <iostream>
// #include <bits/stdc++.h>
using namespace std;

template <class T> 
class stack
{
    T *arr;
    int front;
    public:
    stack()
    {
        arr = new char(10);
        front = -1;
    }

    void pop()
    {
        front--;
    }

    void push(T d)
    {
        arr[++front] = d;
    }

    char top()
    {
        return arr[front];
    }

    bool empty()
    {
        return front < 0;
    }

};

void Parenthesis(string s){
    stack<char> st;

    for (auto c : s)
    {
        if (c == '(' || c == '{' || c == '[')
            st.push(c);
        else if (c == ')' || c == '}' || c == ']')
        {
            if (!st.empty() && (st.top() == '{' && c == '}') || (st.top() == '[' && c == ']') || (st.top() == '(' && c == ')'))
            {
                st.pop();
            }else
            {
                cout<<"False"<<endl;
                return;
            }
        }
    }
    cout<<"True"<<endl;
}

int p(char c)
{
    if (c == '+' || c == '-')
        return 1;
    else 
        return 2;
}

string post(string s){
    string postfix = "";
    stack<char> st;
    for (auto c : s)
    {
        if (c == '+' || c == '-' || c == '*' || c == '/' )
        {
            if (st.empty() || p(st.top()) < p(c))
                st.push(c);
            else 
            {
                while(!st.empty() && p(st.top()) >= p(c) && st.top() != '(')
                {
                    postfix += st.top();
                    st.pop();
                }
                st.push(c);
            }
        }
        else if (c == ')')
        {
            while(!st.empty() && st.top() != '(')
            {
                postfix += st.top();
                st.pop();
            }

            if (!st.empty() && st.top() == '(')
                st.pop();
        }
        else if (c == '(')
            st.push(c);
        else {
            postfix += c;
        }
    }

    while(!st.empty())
    {
        postfix+= st.top();
        st.pop();
    }
    return postfix;
}

int stack()
{

}

int main(){
    string s = "(x+y-z)/(a+b*c-q)";
    Parenthesis(s);

    cout<<post(s);

    return 0;
}