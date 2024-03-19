#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/minimum-cost-for-tickets/

class Solution
{

    int mincostTicketsHelper(vector<int> &days, vector<int> &costs, int i)
    {
        // Base Condn
        if (i >= days.size())
            return 0;

        // Soln For 1
        // taking for 1 day
        int cost1 = costs[0] + mincostTicketsHelper(days, costs, i + 1);

        // taking for 7 days
        int validDays = 7 + days[i];
        int j = i + 1;
        while (j < days.size() && days[j] < validDays)
            j++;
        int cost7 = costs[1] + mincostTicketsHelper(days, costs, j);

        // taking for 30 days
        validDays = 30 + days[i];
        j = i + 1;
        while (j < days.size() && days[j] < validDays)
            j++;
        int cost30 = costs[2] + mincostTicketsHelper(days, costs, j);

        return min(cost1, min(cost7, cost30));
    }

public:
    int mincostTickets(vector<int> &days, vector<int> &costs)
    {
        return mincostTicketsHelper(days, costs, 0);
    }
};

int main()
{

    return 0;
}