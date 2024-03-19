#include <iostream>
#include <bits/stdc++.h>
using namespace std;


bool isPossibleSol(vector<int> v, int m,int sol){
    int wood = 0;
    
    for (int i=0;i<v.size();i++){
        if (v[i]-sol>0){
            wood+=(v[i]-sol);
        }
    }
    if (wood<m) return false;
    return true;
}

int bs(vector<int> v,int m){
    //wood can be cutted from m=0
    int start=0;
    int end=*max_element(v.begin(),v.end());
    int ans=-1;


    while(start<=end){
        int mid=start+((end-start)>>1);
        if (isPossibleSol( v,m,mid)){
            ans=mid;
            //Right Search
            start=mid +1;
        }else{
            //lEFT sdEARCH
            end=mid-1;
        }
    }
    return ans;
}

int main(){
    vector<int> v{15,15,20,17};
    int m=9;
    int n=v.size();
    cout<<bs(v,m);
    return 0;
}