#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int segment(int target, int x, int y, int z){
    if (target == 0)    return 0;               //same as coin_selectiononly check for max   base condn
    if (target < 0)    return INT_MIN;

    int a,b,c;

    a = segment(target-x,x,y,z) + 1;
    b = segment(target-y,x,y,z) + 1;          // Add so it count no of function callback
    c = segment(target-z,x,y,z) + 1;

    int ans = max(a,max(b,c));
    
    return ans;
}

int main(){
    
    int ans = segment(7,5,2,2);
    if (ans < 0){
        ans = 0;
    }

    cout<<ans;
    return 0;
}