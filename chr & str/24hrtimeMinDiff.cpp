#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/minimum-time-difference/

class Solution
{
public:
    int findMinDifference(vector<string> &timePoints)
    {
        vector<int> minutes;

        for (int i = 0; i < timePoints.size(); i++)
        {
            int hr = stoi(timePoints[i].substr(0, 2));
            int minu = stoi(timePoints[i].substr(3, 2));
            minutes.push_back((hr * 60 + minu));
        }

        sort(minutes.begin(), minutes.end());

        int mini = 1440 + minutes[0] - minutes[minutes.size() - 1];

        for (int i = 1; i < minutes.size(); i++)
        {
            mini = min(mini, minutes[i] - minutes[i - 1]);
        }
        return mini;
    }
};