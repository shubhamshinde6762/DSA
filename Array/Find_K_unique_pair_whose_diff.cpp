#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int kdiff(vector<int> v,int k){
    sort(v.begin(),v.end());
    int i=0,j=1;
    int ans=0;
    while(j<v.size()){
        int diff=v[j]-v[i];
        if (diff==k){
            cout<<v[i]<<" "<<v[j]<<endl;
            ans++;
            j++;
        }else if (diff>k){
            i++;
        }else{
            j++;
        }
        if (i==j) j++;
    }
    return ans;
}

int main(){
    vector<int> v{5,6,4,7,8,9,1,2,3,5};
    int k=2;
    int ans=kdiff(v,k);
    cout<<ans;
    return 0;
}