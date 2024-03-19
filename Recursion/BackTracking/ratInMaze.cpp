//{ Driver Code Starts
// Initial template for C++
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{

    bool isSafe(vector<vector<int>> &m, vector<vector<bool>>  &visited, int i, int j, int &n)
    {
        if (((i >= 0 && j >= 0) && (i < n  && j < n) ) && visited[i][j] == 0 && m[i][j] == 1)
            return true;
        return false;
    }

    void path(vector<vector<int>> &m, vector<vector<bool>>  &visited,  int i, int j, vector<string> &ans, string tstr, int &n)
    {

        if (i == n - 1 && j == n - 1)
        {
            ans.push_back(tstr);
            return;
        }

        // Down Travelṇ
        if (isSafe(m, visited, i + 1, j, n))
        {
            visited[i + 1][j] = true;
            path(m, visited, i + 1, j, ans, tstr + 'D', n);
            visited[i + 1][j] = false;
        }
        // Right Travel
        if (isSafe(m, visited, i, j + 1,  n))
        {
            visited[i][j + 1] = true;
            path(m, visited, i, j + 1, ans, tstr + 'R', n);
            visited[i][j + 1] = false;
        }
        // Left Travel
        if (isSafe(m, visited, i, j - 1,  n))
        {
            visited[i][j - 1] = true;
            path(m, visited, i, j - 1, ans, tstr + 'L', n);
            visited[i][j - 1] = false;
        }
        // up Travel
        if (isSafe(m, visited, i - 1, j,  n))
        {
            visited[i - 1][j] = true;
            path(m, visited, i - 1, j, ans, tstr + 'U', n);
            visited[i - 1][j] = false;        //
        }
        return;
    }

public:
    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        // Your code goes here
        

        vector<vector<bool>> visited(n, vector<bool>(n, 0));
        visited[0][0] == true;
        vector<string> ans;

        string tstr = "";

        path(m, visited, 0, 0, ans, tstr, n);

        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";
        cout << endl;
        return ans;
    }
};



int main()
{
    vector<vector<int>> m{{1,0,0},
                         {1,1,0},
                         {1,1,1}};
    
    Solution obj;
    vector<string> result = obj.findPath(m, 3);
    sort(result.begin(), result.end());
    if (result.size() == 0)
        cout << -1;
    else
        for (int i = 0; i < result.size(); i++)
            cout << result[i] << " ";
    cout << endl;
}
