#include <iostream>
#include <vector>
using namespace std;

class fenwick
{
    vector<int> bit;
    int n;

public:
    fenwick(vector<int> &nums)
    {
        n = nums.size();
        bit = vector<int>(n + 1);
        for (int i = 0; i < n; i++)
            update(i + 1, nums[i]);
    }

    void update(int id, int val)
    {
        while (id <= n)
        {
            bit[id] += val;
            id += (id & -id);
        }
    }

    int query(int id)
    {
        int ans = 0;
        while (id > 0)
        {
            ans += bit[id];
            id -= (id & -id);
        }

        return ans;
    }

    int query(int l, int r)
    {
        return query(r) - query(l - 1);
    }
};

void displayMenu()
{
    cout << "Fenwick Tree Operations Menu:\n";
    cout << "1. Update\n";
    cout << "2. Query single position\n";
    cout << "3. Query range\n";
    cout << "4. Exit\n";
    cout << "Enter your choice: ";
}

int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements:\n";
    for (int i = 0; i < n; ++i)
    {
        cin >> nums[i];
    }

    fenwick tree(nums);

    while (true)
    {
        displayMenu();
        int choice;
        cin >> choice;
        if (choice == 4)
        {
            break;
        }

        switch (choice)
        {
        case 1:
        {
            int id, val;
            cout << "Enter index and value to update: ";
            cin >> id >> val;
            tree.update(id, val);
            break;
        }
        case 2:
        {
            int id;
            cout << "Enter index to query: ";
            cin >> id;
            int result = tree.query(id);
            cout << "Query result at index " << id << " is " << result << endl;
            break;
        }
        case 3:
        {
            int l, r;
            cout << "Enter range (l, r) to query: ";
            cin >> l >> r;
            int result = tree.query(l, r);
            cout << "Query result for range (" << l << ", " << r << ") is " << result << endl;
            break;
        }
        default:
            cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}
