#include <iostream>
#include <bits/stdc++.h>
using namespace std;


class Solution {             //https://leetcode.com/problems/combination-sum-ii/
public:

    void Helper(vector<int>&cand, int target, vector<vector<int>>&ans, vector<int>&temp, int index)
    {
        if (target == 0){
            ans.push_back(temp);
            return;
        }

        if (target < 0 )
            return;


        for (int i = index; i < cand.size(); i++)
        {
            if (index < i && cand[i] == cand[i - 1])
            {
                continue;             // because to avoid duplicate
            }
            temp.push_back(cand[i]);
            Helper(cand, target - cand[i], ans, temp, i+1);
            // Back_tracking
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());    //Soerted to remove duplicates and get required output as leetcode

        vector<vector<int>> ans;
        vector<int> temp;
        Helper(candidates, target, ans, temp, 0);
        return ans;
    }
};

int main(){
    
    return 0;
}