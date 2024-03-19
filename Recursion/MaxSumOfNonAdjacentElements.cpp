#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void MaxSum(vector<int> arr, int i, int sum, int& maxi){
    if (i >= arr.size())  {
        maxi = max(sum , maxi);
        return;
    }

    //exclude 
    MaxSum(arr, i+1, sum, maxi);

    // include condn
    sum += arr[i];
    MaxSum(arr, i+2, sum, maxi); 
    
    
}

int main(){
    vector<int> v{2,1,4,9};
    int ans = 0;
    MaxSum(v,0,0,ans);
    cout<<ans;
    return 0;
}