#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Node {
public:
  Node *next;
  int data;

  Node() : next(nullptr), data(0) {}
  Node(int _data) : next(nullptr), data(_data) {}
};

void print(Node *head) {
  while (head != nullptr) {
    cout << head->data << " ";
    head = head->next;
  }
  cout << endl;
}

int getLen(Node *head) {
  int i = 0;
  while (head != nullptr) {
    head = head->next;
    i++;
  }
  return i;
}

Node *reverse(Node *head) {
  if (head == nullptr || head->next == nullptr)
    return head;

  Node *pre = nullptr;
  Node *current = head;
  Node *forward = head->next;

  while (forward != nullptr) {
    forward = current->next;
    current->next = pre;
    pre = current;
    current = forward;
  }

  return pre;
}

Node *mid(Node *head) {
  if (head == nullptr || head->next == nullptr)
    return head;

  Node *slow = head;
  Node *fast = head;

  while (slow->next != nullptr && fast->next != nullptr) {
    fast = fast->next;
    if (fast->next != nullptr) {
      fast = fast->next;
      slow = slow->next;
    }
  }

  return slow;
}

void SortLL(Node *&head) {
  Node *zeroHead = new Node(-1);
  Node *oneHead = new Node(-1);
  Node *twoHead = new Node(-1);

  Node *zeroTail = zeroHead;
  Node *oneTail = oneHead;
  Node *twoTail = twoHead;

  Node *current = head;

  while (current != nullptr) {
    if (current->data == 0) {
      Node *temp = current;
      current = current->next;
      temp->next = nullptr;

      // append to zero
      zeroTail->next = temp;
      zeroTail = temp;

    } else if (current->data == 1) {
      Node *temp = current;
      current = current->next;
      temp->next = nullptr;

      // append to one
      oneTail->next = temp;
      oneTail = temp;

    } else if (current->data == 2) {
      Node *temp = current;
      current = current->next;
      temp->next = nullptr;
      // append to two

      twoTail->next = temp;
      twoTail = temp;
    }
  }

  Node *temp = twoHead;
  twoHead = twoHead->next;
  twoTail->next = nullptr;
  temp->next = nullptr;

  temp = oneHead;
  oneHead = oneHead->next;
  oneTail->next = twoHead;
  temp->next = nullptr;

  temp = zeroHead;
  zeroHead = zeroHead->next;
  temp->next = nullptr;
  zeroTail->next = oneHead;

  head = zeroHead;

  return;
}

int main() {
  Node *head = nullptr;
  Node *a = new Node(1);
  head = a;
  Node *b = new Node(2);
  a->next = b;
  Node *c = new Node(2);
  b->next = c;
  Node *d = new Node(0);
  c->next = d;
  Node *e = new Node(0);
  d->next = e;
  Node *f = new Node(2);
  e->next = f;
  Node *g = new Node(0);
  f->next = g;
  Node *h = new Node(1);
  g->next = h;
  Node *i = new Node(2);
  h->next = i;
  i->next = nullptr;
  print(head);

  SortLL(head);

  print(head);

  return 0;
}