#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int segment(vector<int>& arr,int target){
    if (target == 0)    return 0;               //same as coin_selectiononly check for max   base condn
    else if (target < 0)    return INT_MIN;

    int maxi = INT_MIN;

    for (int i =0; i < arr.size() ; i++){
        int ans = segment(arr, target - arr[i]);
        if (ans != INT_MIN)     maxi = max(maxi,ans+1);
    }

    return maxi;
}

int main(){
    vector<int> v{3,2,5,7};

    cout<<segment(v,7);
    return 0;
}