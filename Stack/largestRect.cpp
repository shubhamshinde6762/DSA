#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/largest-rectangle-in-histogram/

class Solution {
    void HelperPreMin(vector<int> &h, vector<int> &p)
    {
        stack<int> s;
        s.push(-1);

        for (int i = 0; i < h.size(); i++)
        {
            while(s.top() != -1 && h[i] <= h[s.top()])
                s.pop();
            p[i] = s.top();
            s.push(i);
        }
    }

    void HelperNxtMin(vector<int> &h, vector<int> &n)
    {
        stack<int> s;
        s.push(h.size());

        for (int i = h.size() - 1; i >= 0; i--)
        {
            while(s.top() != h.size() && h[i] <= h[s.top()])
                s.pop();
            n[i] = s.top();
            s.push(i);
        }
    }

public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        vector<int> pre(heights.size());
        vector<int> nxt(heights.size());
        
        HelperPreMin(heights, pre);
        HelperNxtMin(heights, nxt);
        
        int maxi = -1;
        for (int i = 0; i < heights.size(); i++)
            maxi = max(maxi, (nxt[i] - pre[i] - 1) * heights[i]);

        return maxi;
    }
};