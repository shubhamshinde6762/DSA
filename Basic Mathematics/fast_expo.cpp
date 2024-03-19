#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int fast_expo(int a,int b){
    int ans = 1;

    while(b>0){
        if (b&1){       //if b is odd
            ans = ans * a;
        }

        a*=a;
        b>>=1;    //Divide by 2
    }
    return ans;
}

int main(){
    cout<<fast_expo(2,10);
    return 0;
}