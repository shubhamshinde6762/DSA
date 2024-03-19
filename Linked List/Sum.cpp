#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node() : data(0), next(nullptr) {}
    Node(int _data) : data(_data), next(nullptr) {}
};

void reverse(Node *&head)
{
    Node *pre = nullptr;
    Node* current = head;
    Node* forward = head->next;

    while(current != nullptr)
    {
        forward = current->next;
        current->next = pre;
        pre = current;
        current = forward;
    }
}

void print(Node *&head)
{
    // Step 1 Create temp pointer
    Node *temp = head;
    while (temp != nullptr)
    {
        // step 2   PRINT DATA
        cout << temp->data << endl;
        // step 3  Go to nxt Node
        temp = temp->next;
    }
}

int main()
{
    Node *head1 = nullptr;
    Node *a = new Node(1);
    head1 = a;
    Node *b = new Node(2);
    a->next = b;
    Node *c = new Node(2);
    b->next = c;
    Node *d = new Node(4);
    c->next = d;
    d->next = nullptr;

    Node *e = new Node(5);
    Node *head2 = e;
    Node *f = new Node(5);
    e->next = f;
    Node *g = new Node(6);
    f->next = g;
    Node *h = new Node(2);
    g->next = h;
    Node *i = new Node(2);
    h->next = i;
    i->next = nullptr;

    reverse(head1);
    reverse(head2);
    return 0;
}