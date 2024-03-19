#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *pre;

    Node() : data(0), next(nullptr), pre(nullptr) {}
    Node(int _data) : data(_data), next(nullptr), pre(nullptr) {}
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
    // // step 1   Create New Node
    // Node *newNode = new Node(data);
    // // step 2    copy head adress to new's next ptr
    // newNode->next = head;
    // // if Head is null then tail also null in this case added element is head as well as tail
    // // step 3   change head ptr to new node
    // // Bydefalt head should be changed changed
    // if (head == nullptr)
    //     tail = newNode;
    // head = newNode;

    if (head == nullptr)
    {
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else
    {
        Node *newNode = new Node(data);
        head->pre = newNode;
        newNode->next = head;
        head = newNode;
    }
}

void insertAtTail(Node *&head, Node *&tail, int data)
{
    // // step 1   Create new node
    // Node *newNode = new Node(data);
    // // step 2   tail next be newNode
    // tail->next = newNode;
    // // step 3        if head is null then tail is also null in that case head and tail represents added node
    // if (head == nullptr)
    //     head = newNode;
    // tail = newNode;
    if (head == nullptr)
    {
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else
    {
        Node* newNode = new Node(data);
        tail->next = newNode;
        newNode->pre = tail;
        tail = newNode;
    }
}

void insertAtPosn(Node *&head, Node *&tail, int data, int posn)
{
    // Case 1
    if (posn == 0)
    {
        insertAtHead(head, tail, data);
        return;
    }

    // case 2
    int len = findLength(head);
    if (posn > len)
    {
        insertAtTail(head, tail, data);
        return;
    }

    // case 3    Insert at in betn head and tail
    Node *newNode = new Node(data);

    Node *prev = head;
    int i = 1;
    while (i < posn)
    {
        prev = prev->next;
        i++;
    }

    Node *current = prev->next;

    newNode->next = current;
    newNode->pre = prev;
    prev->next = newNode;
    current->pre = newNode;
}

void deleteData(Node *&head, Node *&tail, int posn)
{
    int len = findLength(head);

    if (posn < 0 || posn > len || head == nullptr)
    {
        cout << "Deletion Not Possible" << endl;
        return;
    }

    // case 1
    if (posn == 1)
    {
        Node *temp = head;
        head = head->next;
        temp->next = nullptr;
        head->pre = nullptr;
        delete[] temp;
    }

    // Case 2
    if (posn == len)
    {
        // cout<<len;
        int i = 1;
        Node *lastOne = tail;
        tail = tail->pre;
        tail->next = nullptr;
        lastOne->pre = nullptr;
        delete lastOne;
        return;
    }

    // Case 3
    int i = 1;
    Node *pre = head;
    while (i < posn - 1)
    {
        pre = pre->next;
        i++;
    }
    Node *current = pre->next;
    pre->next = current->next;
    current->next->pre = pre->next;
    current->next = nullptr;
    current->pre = nullptr;
    delete current;
    return;
}

int main()
{
    Node *head = nullptr;
    Node *tail = nullptr;
    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 3);
    insertAtHead(head, tail, 4);
    insertAtHead(head, tail, 5);
    insertAtHead(head, tail, 6);
    insertAtHead(head, tail, 7);
    insertAtHead(head, tail, 8);
    insertAtHead(head, tail, 9);
    insertAtTail(head, tail, 100);

    insertAtPosn(head, tail, 500, 8);
    print(head);
    deleteData(head, tail, 10);
    print(head);
}