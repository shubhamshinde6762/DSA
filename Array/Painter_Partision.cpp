#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool isPossibletoPaint(vector<int> v,int n,int k,int sol){
    
    int time=0;
    int worker=1;
    
    for (int i=0;i<n;i++){
        if (v[i]>sol){
            return false;
        }
        if (time+v[i]>sol){
            worker++;
            time=v[i];
            if (worker>k){
                return false;
            }
        }else{
            time+=v[i];
        }
    }
    return true;
}

int bs(vector<int> v,int n,int k){
    int start=0;
    int end=accumulate(v.begin(),v.end(),0);
    int ans=-1;

    while(start<=end){

        if (k>n) return -1;

        int mid=start+((end-start)>>1);
        if (isPossibletoPaint(v,n,k,mid)){
            //left Search
            ans=mid;
            end=mid-1;
        }else{
            //Right Search
            start=mid+1;
        }
    }
    return ans;
}

int main(){
    vector<int> v{10,20,30,40};
    int k=2;
    int n=v.size();
    cout<<bs(v,n,k);
    return 0;
}