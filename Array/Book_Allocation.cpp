#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool isPossibleSol(vector<int> v, int n, int m, int mid)
{
    int studentno = 1;
    int pageno = 0;

    for (int i = 0; i < n; i++)
    {
        if (v[i] > mid)
        {
            return false;
        }
        if (pageno + v[i] > mid)
        {
            studentno++;
            pageno = v[i];
            if (studentno > m)
                return false;
        }
        else
        {
            pageno += v[i];
        }
    }
    return true;
}

int bs(vector<int> v, int n, int m)
{
    if (m > n)
    {
        return -1;
    }
    int start = 0;
    int end = accumulate(v.begin(), v.end(), 0);
    int ans = -1;

    while (start <= end)
    {
        int mid = start + ((end - start) >> 1);

        if (isPossibleSol(v, n, m, mid))
        {
            // left Search
            ans = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> v{12, 34, 67, 90};
    int m = 2;
    int n = v.size();
    cout << bs(v, n, m);
    return 0;
}