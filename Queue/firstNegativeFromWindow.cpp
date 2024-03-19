//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K) {
    
    vector<long long> ans;
    
    deque<long long> q;
    
    // Solve for 1 case
    for (long long int i = 0; i < K ; i++)
        if (A[i] < 0)
            q.push_back(i);
            
    for (long long int i = K; i < N ; i++)
    {
        // Solve for old Window
        if (!q.empty())
            ans.push_back(A[q.front()]);
        else
            ans.push_back(0);
            
        // Delete element out of window for current window
        while(!q.empty() && i - K >= q.front())
            q.pop_front();
            
        // insert new elemnt
        if (A[i] < 0)
            q.push_back(i);
    }
    
    // Answer for Last Window
    
    if (!q.empty())
            ans.push_back(A[q.front()]);
        else
            ans.push_back(0);
    
    return ans;
 }