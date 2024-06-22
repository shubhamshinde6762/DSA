#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class SegTree
{
    vector<int> t;
    int len;

    void build(vector<int> &a, int v, int tl, int tr)
    {
        if (tl == tr)
        {
            t[v] = a[tl];
            return;
        }

        int tm = tl + (tr - tl) / 2;

        build(a, 2 * v, tl, tm);
        build(a, 2 * v + 1, tm + 1, tr);
        t[v] = t[2 * v] + t[2 * v + 1];
    }

    int query(int v, int tl, int tr, int l, int r)
    {
        if (tl > r || tr < l)
            return 0;
        else if (tl >= l && tr <= r)
            return t[v];

        int tm = tl + (tr - tl) / 2;
        int left = query(2 * v, tl, tm, l, r);
        int right = query(2 * v + 1, tm + 1, tr, l, r);
        return left + right;
    }

    void update(int v, int tl, int tr, int id, int val)
    {
        if (tl == tr && tl == id)
        {
            t[v] = val;
            return;
        }

        if (id > tr || id < tl)
            return;

        int tm = tl + (tr - tl) / 2;
        update(2 * v, tl, tm, id, val);
        update(2 * v + 1, tm + 1, tr, id, val);
        t[v] = t[2 * v] + t[2 * v + 1];
        return;
    }

public:
    SegTree() {}
    SegTree(int _len) : len(_len)
    {
        t.resize(4 * len);
    }

    void build(vector<int> &a)
    {
        build(a, 1, 0, len - 1);
    }

    int query(int l, int r)
    {
        query(1, 0, len - 1, l, r);
    }

    void update(int id, int val)
    {
        update(1, 0, len - 1, id, val);
    }
};

int main()
{
    int n, choice, l, r, id, val;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    SegTree segTree(n);
    segTree.build(arr);

    while (true)
    {
        cout << "\nMenu:\n";
        cout << "1. Range Sum Query\n";
        cout << "2. Update Value\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter the range (l r): ";
            cin >> l >> r;
            cout << "Sum in range [" << l << ", " << r << "] is " << segTree.query(l, r) << endl;
            break;

        case 2:
            cout << "Enter the index and new value: ";
            cin >> id >> val;
            segTree.update(id, val);
            cout << "Value updated.\n";
            break;

        case 3:
            return 0;

        default:
            cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}