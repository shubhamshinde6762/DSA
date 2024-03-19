#include <iostream>
#include <bits/stdc++.h>
using namespace std;


class Node
{
public:
    bool data;
    Node *next;
    Node *pre;

    Node() : data(0), next(this), pre(this) {}
    Node(bool _data) : data(_data), next(this), pre(this) {}
    int arr[5] = {};
};

void display(Node *head)
{
    Node *temp = head;
    cout<<head->data<<" ";
    temp = temp->next;
    while (head != temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

bool check(Node *head, int n)
{
    int temp = 0;
    int track = 0;
    Node *start = head;
    while (true)
    {
        if (start == head)
            track++;
        if (track == 3)
            break;

        if (start->data == 0)
            temp++;
        else
            temp = 0;

        if (temp == n)
        {
            while (temp > 0)
            {
                start->data = 1;
                start = start->pre;
                temp--;
            }
            return true;
        }
        start = start->next;
    }
    return false;
}

void create(Node *head)
{
    Node *pre = head->pre;

    int i = 0;
    while (i < 6)
    {
        pre = head->pre;

        Node *newNode = new Node;

        head->pre = newNode;
        newNode->next = head;

        pre->next = newNode;
        newNode->pre = pre;

        i++;
    }
}

void del1(Node *head, int j)
{
    Node *start = head;
    while (j > 0)
    {
        start = start->next;
        j--;
    }
    if (start->data)
    {
        start->data = false;
        cout << "Tickets Cancelled !" << endl;
        
    }
    else
    {
        cout << "Seat is Not Booked !" << endl;
    }
    cout<<endl;
}

int main()
{
    Node *rowHead = new Node[10];

    vector<int> seats(10, 7);

    int i = 0;
    while (i < 10)
        create((&rowHead[i++]));

    while (true)
    {
        int choice = 0;

        cout << endl <<"Here are the Options:-" << endl;
        cout << "1. List of Available Seats : " << endl;
        cout << "2. Book Seats : " << endl;
        cout << "3. Cancel Booking" << endl;
        cout << "Else Exit"<<endl<<endl;

        cin >> choice;

        if (choice == 1)
        {
            i = 0;
            while (i < 10)
            {
                display(&rowHead[i++]);
            }
        }
        else if (choice == 2)
        {
            cout<<endl;
            i = 0;
            while (i < 10)
            {
                display(&rowHead[i++]);
            }

            int n;
            cout << "How many Tickets do you want to book ? : ";
            cin >> n;

            if (n > 7 || n < 0)
            {
                cout<<"Wromg No of Tickets Continuing..."<<endl;
                continue;
            }

            cout << "In Which Row do you want seats? : ";
            cin >> i;

            if (check(&rowHead[i], n))
                cout << "Congrats! Tickets are Booked..." << endl;
            else
                cout << "No Available Seats in " << i << " row" << endl;
            cout<<endl;
        }
        else if (choice == 3)
        {
            cout<<endl;
            i = 0;
            while (i < 10)
            {
                display(&rowHead[i++]);
            }
            int i = 0;
            int j = 0;
            cout << "Enter The Row Number ? : ";
            cin >> i;
            cout << "Enter The Column Number ? : ";
            cin >> j;

            if (!(i < 10 && j < 7))
            {
                cout << "No such Seat present." << endl;
            }
            else
            {
                del1(&rowHead[i], j);
            }
            cout<<endl;
        }
        else
            break;
    }
    return 0;
}