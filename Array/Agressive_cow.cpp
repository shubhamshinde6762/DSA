#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool isPossibleSol(vector<int> v, int k, int sol)
{
    int cows = 1;
    int pos = v[0];

    if (v[v.size() - 1] - pos < sol)
        return false;

    for (int i = 1; i < v.size(); i++)
    {
        if (v[i] - pos >= sol)
        {
            cows++;
            pos = v[i];
        }
        if (cows == k)
            return true;
    }
    return false;
}

int bs(vector<int> v, int k, int n)
{
    // if (k>n) return -1;

    int start = 0;
    int end = v[(n - 1)] - v[0];
    int ans = -1;

    while (start <= end)
    {
        int mid = start + ((end - start) >> 1);

        if (isPossibleSol(v, k, mid))
        {
            ans = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> v{1,2,4,8,9};
    int k = 3;
    int n = v.size();
    cout << bs(v, k, n);
    return 0;
}