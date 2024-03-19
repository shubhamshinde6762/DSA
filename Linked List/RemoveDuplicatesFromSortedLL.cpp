#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    Node *next;
    int data;

    Node() : next(nullptr), data(0) {}
    Node(int _data) : next(nullptr), data(_data) {}
};

void print(Node *head)
{
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int getLen(Node *head)
{
    int i = 0;
    while (head != nullptr)
    {
        head = head->next;
        i++;
    }
    return i;
}

Node *reverse(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;

    Node *pre = nullptr;
    Node *current = head;
    Node *forward = head->next;

    while (forward != nullptr)
    {
        forward = current->next;
        current->next = pre;
        pre = current;
        current = forward;
    }

    return pre;
}

Node *mid(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;

    Node *slow = head;
    Node *fast = head;

    while (slow->next != nullptr && fast->next != nullptr)
    {
        fast = fast->next;
        if (fast->next != nullptr)
        {
            fast = fast->next;
            slow = slow->next;
        }
    }

    return slow;
}

void removeDuplicate(Node* head)
{
    if (head == nullptr || head->next ==nullptr)    
        return;
    
    while(head->next != nullptr)
    {
        if (head->data == head->next->data)
        {
            Node* temp = head->next;
            head->next = head->next->next;
            delete temp;
        }else{
            head = head->next;  
        }
    }
}

int main()
{
    Node *head = nullptr;
    Node *a = new Node(1);
    head = a;
    Node *b = new Node(2);
    a->next = b;
    Node *c = new Node(2);
    b->next = c;
    Node *d = new Node(4);
    c->next = d;
    Node *e = new Node(5);
    d->next = e;
    Node *f = new Node(5);
    e->next = f;
    Node *g = new Node(6);
    f->next = g;
    Node *h = new Node(2);
    g->next = h;
    Node *i = new Node(2);
    h->next = i;
    i->next = nullptr;

    removeDuplicate(head);
    print(head);
    return 0;
}