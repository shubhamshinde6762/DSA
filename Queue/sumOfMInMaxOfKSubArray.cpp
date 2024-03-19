// #include <bits/stdc++.h> 
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// https://www.codingninjas.com/studio/problems/sum-of-minimum-and-maximum-elements-of-all-subarrays-of-size-k_1171047?leftPanelTabValue=SUBMISSION

void HelperMini(vector<int>&nums,long long int &mini, int &k)
{
	// Solution for 1 case
	deque<int> q;

	for (int i = 0; i < k; i++)
	{
		// remove larger NUmber
		while(!q.empty() && nums[q.back()] > nums[i])
			q.pop_back();
		q.push_back(i);
	}

	mini += nums[q.front()];

	for (int i = k; i < nums.size(); i++)
	{
		// remove larger elements
		while(!q.empty() && nums[q.back()] > nums[i])
			q.pop_back();

		// Remove elements which are out of window
		while(!q.empty() && i - k >= q.front())
			q.pop_front();

		// pushing
		q.push_back(i);
		
		// answer
		mini += nums[q.front()];
	}
}

void HelperMaxi(vector<int>&nums, long long int &maxi, int &k)
{
	// Solution for 1 case
	deque<int> q;

	for (int i = 0; i < k; i++)
	{
		// remove smaller NUmber
		while(!q.empty() && nums[q.back()] < nums[i])
			q.pop_back();
		q.push_back(i);
	}

	maxi += nums[q.front()];

	for (int i = k; i < nums.size(); i++)
	{
		// remove smaller elements
		while(!q.empty() && nums[q.back()] < nums[i])
			q.pop_back();

		// Remove elements which are out of window
		while(!q.empty() && i - k >= q.front())
			q.pop_front();

		q.push_back(i);
		
		// answer
		maxi += nums[q.front()];
	}
}

long long sumOfMaxAndMin(vector<int> &nums, int n, int k) {
	// Write your code here.
	long long int mini = 0;
	long long int maxi = 0;

	HelperMini(nums, mini, k);
	HelperMaxi(nums, maxi, k);

	return (mini + maxi);
}
