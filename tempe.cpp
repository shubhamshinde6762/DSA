#include <iostream>
#include <bits/stdc++.h>
using namespace std;

map<string, bool> a;
map<string, bool> b;

class Node
{
public:
    string data;
    Node *next;

    Node() : data(""), next(nullptr) {}
    Node(string _data) : data(_data), next(nullptr) {}
};

void createA(Node *&start, int n)
{
    start = new Node;
    Node* head = start;

    cout << "Enter data " << endl;

    Node *pre = start;

    for (int i = 0; i < n; i++)
    {
        while (true)
        {
            string t = "";
            cin >> t;
            if (!a[t])
            {
                head = new Node(t);
                pre->next = head;
                pre = head;
                a[t] = true;
                break;
            }
            else
                cout << "Data Already Existed" << endl;
        }
    }
}

void createB(Node* &start, int n)
{
    start = new Node;
    Node* head = start;

    cout << "Enter data " << endl;

    Node *pre = head;

    for (int i = 0; i < n; i++)
    {
        while (true)
        {
            string t = "";
            cin >> t;
            if (!b[t])
            {
                head = new Node(t);
                pre->next = head;
                pre = head;
                b[t] = true;
                break;
            }
            else
                cout << "Data Already Existed" << endl;
        }
    }
}

Node *inter(Node *A, Node *B)
{
    Node *temp1, *temp2;
    temp1 = A;
    temp2 = B;

    Node *head = new Node;
    Node *temp3 = head;
    Node *pre = head;

    while (temp1)
    {
        while (temp2)
        {
            if (temp1->data == temp2->data)
            {
                temp3 = new Node;
                temp3->data = temp1->data;
                pre->next = temp3;
                pre = temp3;
            }
            temp2 = temp2->next;
        }
        temp2 = B;
        temp1 = temp1->next;
    }

    return head->next;
}

Node *uni(Node *A, Node *B)
{
    Node *head = new Node;
    Node *temp1 = A;
    Node *temp2 = B;
    Node* temp3 = head;

    Node *pre = head;

    while (temp1)
    {
        temp3 = new Node;
        temp3->data = temp1->data;
        pre->next = temp3;
        pre = temp3;
        temp1 = temp1->next;
    }

    temp1 = A;
    while (temp2)
    {
        bool flag = 0;
        while (temp1)
        {
            if (temp1->data == temp2->data)
                flag = 1;
            temp1 = temp1->next;
        }

        temp1 = A;
        
        if (!flag)
        {
            temp3 = new Node;
            temp3->data = temp2->data;
            pre->next = temp3;
            pre = temp3;
            flag = 0;
        }
        temp2 = temp2->next;
    }

    return head->next;
}

void display(Node* head)
{
    while(head)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

int main()
{
    int n;
    cout << "Enter No of Total Students : ";
    cin >> n;
    cout << endl;

    Node *A = nullptr;
    Node *B = nullptr;

    int a;
    cout << "Enter No of Students Who like Vannilla IceCream : ";
    cin >> a;
    createA(A, a);
    A = A->next;
    cout << endl;

    int b;
    cout << "Enter No of Students Who like butterScoch IceCream : ";
    cin >> b;
    createB(B, b);
    B = B->next;
    cout << endl;

    display(A);
    display(B);

    display(inter(A, B));
    display(uni(A, B));



    return 0;
}