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

void insertAtTail(Node *&head, Node *&tail, int data)
{
    // step 1   Create new node
    Node *newNode = new Node(data);
    // step 2   tail next be newNode
    tail->next = newNode;
    // step 3        if head is null then tail is also null in that case head and tail represents added node
    if (head == nullptr)
        head = newNode;
    tail = newNode;
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

    Node *pre = head;
    int i = 1;
    while (i < posn)
    {
        pre = pre->next;
        i++;
    }

    Node *current = pre->next;

    newNode->next = current;
    pre->next = newNode;
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
        delete[] temp;
    }

    // Case 2
    if (posn == len)
    {
        // cout<<len;
        int i = 1;
        Node *temp = head;
        while (i < posn - 1)
        {
            temp = temp->next;
            i++;
        }
        tail = temp;
        temp = tail->next;
        tail->next = nullptr;
        delete temp;
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
    current->next = nullptr;
    delete current;
    return;
}

Node* reverse(Node* &pre, Node* &current)
{
    if (current == nullptr)
        return pre;

    Node* next = current->next;
    current->next = pre;

    return reverse(current, next);
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
    deleteData(head, tail, 9);
    print(head);
    Node*temp = head;

    head = reverse(tail->next, head);
    tail = temp;
    print(head);
}