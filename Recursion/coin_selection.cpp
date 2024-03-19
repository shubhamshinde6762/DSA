#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& arr,int target){

    if (target == 0) return 0;                   //return 0 if successfully target becoming zero 
    else if (target<0) return INT_MAX;               //Base cONDITION

    int mini = INT_MAX;

    for (int i = 0; i < arr.size(); i++ ){
        int ans = solve(arr,target - arr[i]);

        if (ans != INT_MAX) mini = min(mini , ans+1);        // target becomes zero take 1 currency so add it
    }

    return mini;
}

int main(){
    vector<int> v{1,2,3};
    cout<<solve(v,10);
    return 0;
}