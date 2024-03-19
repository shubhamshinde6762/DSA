#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/generate-parentheses/

class Solution {
public:

    void solve(int n, vector<string> &ans, int o, int c, string tstr)
    {
        // Base Condn
        if (o == 0 && c == 0)
        {
            ans.push_back(tstr);
            return;
        }
        
        // soln for 1 case
        
        // insert open
        if (o > 0)
        {   
            tstr.push_back('(');
            solve(n, ans, o-1, c, tstr);
            // backtracking
            tstr.pop_back();
        }

        // insert closed
        if (o < c)
        {
            tstr.push_back(')');
            solve(n, ans, o, c-1, tstr);
            // backtracking
            tstr.pop_back();
        }
        return;
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp = "";
        solve(n, ans, n, n, temp);
        return ans;
    }
};

int main(){
    
    return 0;
}