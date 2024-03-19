#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/group-anagrams/

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        map<string, vector<string>> mp;

        for (auto i : strs)
        {
            string s = i;
            sort(s.begin(), s.end());
            mp[s].push_back(i);
        }

        vector<vector<string>> ans;
        for (auto i = mp.begin(); i != mp.end(); i++)
        {
            ans.push_back(i->second);
        }
        return ans;
    }
};

int main()
{
    return 0;
}