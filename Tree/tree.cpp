#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Tree
{
    public:
    int data;
    Tree* left;
    Tree* right;

    Tree(int _data) : data(_data), left(nullptr), right(nullptr) {};
};

Tree* build()
{
    cout<<"Enter Data : ";
    int _val = 0;
    cin>> _val;

    if (_val == -1)
        return nullptr;

    Tree* root = new Tree(_val);
  
    root->left = build();
    root->right = build();

    return root;
}

void levelOrderTra(Tree* root)
{
    queue<Tree*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        if (q.front() == NULL)
        {
            q.pop();
            if (!q.empty())
                q.push(NULL);
            else
                break;
            cout<<endl;
        }

        cout<<q.front()->data<<" ";
        if (q.front()->left)
            q.push(q.front()->left);
        if (q.front()->right)
            q.push(q.front()->right);
    }
}

void inOrder(Tree* Node)
{
    if (Node)
        return;

    // LNR
    inOrder(Node->left);
    cout<<Node->data<<" ";
    inOrder(Node->right);
}

void preOrder(Tree* Node)
{
    if (Node)
        return;

    // NLR
    cout<<Node->data<<" ";
    preOrder(Node->left);
    preOrder(Node->right);
}

void postOrder(Tree* Node)
{
    if (Node)
        return;

    // LRN
    postOrder(Node->left);
    postOrder(Node->right);
    cout<<Node->data<<" ";
}

int main(){
    
    return 0;
}