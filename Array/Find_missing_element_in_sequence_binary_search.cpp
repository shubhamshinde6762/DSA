#include <iostream>
#include <vector>
using namespace std;

int missing(vector<int> &v,int size){
    int start=0;
    int end=size-1;
    int mid=start+(end-start)/2;
    int ans=-1;

    while(start<=end){
        int element=v[mid];

        if (element==(mid+1)){
            //Right Search
            start=mid+1;
        }else{
            //updating missing Number
            ans=mid+1;

            //Left Search
            end=mid-1;
        }

        mid=start+(end-start)/2;
    }
    return ans;
}

int main(){
    vector<int> v{1,3,4,5,6,7,8,9};

    cout<<missing(v,v.size());
}