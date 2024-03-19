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

int findLength(Node *&head)
{
    int i = 0;
    Node *temp = head;
    while (temp != nullptr)
    {
        i++;
        temp = temp->next;
    }
    return i;
}

void insertAtHead(Node *&head, Node *&tail, int data)
{
    // step 1   Create New Node
    Node *newNode = new Node(data);
    // step 2    copy head adress to new's next ptr
    newNode->next = head;
    // if Head is null then tail also null in this case added element is head as well as tail
    // step 3   change head ptr to new node
    // Bydefalt head should be changed changed
    if (head == nullptr)
        tail = newNode;
    head = newNode;
}

Node* start(Node* head)
{
    if (head == nullptr && head->next == nullptr)
        return head;

    Node* slow = head;
    Node* fast = head;

    while(slow->next != nullptr && fast->next != nullptr)
    {
        fast = fast->next;
        if (fast->next != nullptr)
        {
            fast = fast->next;
            slow = slow->next;

            if (slow == fast)
            {
                slow = head;
                break;
            }
        }
    }
    Node *pre = fast;
    
    while(slow != fast)
    {
        pre = fast;
        slow = slow->next;
        fast = fast->next;
    }
    pre->next = nullptr;
    print(head);
    cout<<endl;
    return slow;
}

int main()
{
    Node *head = nullptr;
    Node *a = new Node(1);
    head = a;
    Node *b = new Node(2);
    a->next = b;
    Node *c = new Node(3);
    b->next = c;
    Node *d = new Node(4);
    c->next = d;
    Node *e = new Node(5);
    d->next = e;
    Node *f = new Node(6);
    e->next = f;
    Node *g = new Node(7);
    f->next = g;
    Node *h = new Node(8);
    g->next = h;
    Node *i = new Node(9);
    h->next = i;
    i->next = f;

    cout<<start(head)->data<<endl;
}