#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {    //https://leetcode.com/problems/combination-sum/

    void Helper(vector<int>&cand, int target, vector<vector<int>>&ans, vector<int>&temp, int index)
    {
        if (target == 0){
            ans.push_back(temp);
            return;
        }

        if (target < 0)
            return;

        for (int i = index; i < cand.size(); i++)
        {
            temp.push_back(cand[i]);
            Helper(cand, target - cand[i], ans, temp, i);
            // Back_tracking
            temp.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        Helper(candidates, target, ans, temp, 0);
        return ans;
    }
};

int main(){
    return 0;
}