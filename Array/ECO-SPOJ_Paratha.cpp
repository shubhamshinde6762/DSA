#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool isPossibleParatha(vector<int> v,int n, int p,int sol){
    sort(v.begin(),v.end());
    int paratha=0;
    //Calculate How Many Paratha are made in our sol
    for (int i=0;i<n;i++){
        float temp = sqrt((2*(sol/v[i])+0.25))-0.5;
        paratha+=temp;
    }
    if (paratha<p) return false;
    return true;

}

int bs(vector<int> v,int n,int p){
    int start=0;
    int end=*max_element(v.begin(),v.end()) *((n*(n+1))>>1);
    int ans=-1;

    while(start<=end){
        int mid=start+((end-start)>>1);
        if (isPossibleParatha(v,n,p,mid)){
            ans=mid;
            end=mid-1;
            //Left Search
        }else{
            //Right Search
            start=mid+1;
        }
    }
    return ans;
}

int main(){
    vector<int> v{4,1,2,3,4};
    int p=10;
    int n=v.size();
    cout<<bs(v,n,p);
    return 0;
}
