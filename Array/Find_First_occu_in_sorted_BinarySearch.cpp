#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

int occu(vector<int> v,int size,int target){
    int start=0;
    int end=size-1;
    int mid=start+(end-start)/2;

    int index=-1;

    while(start<=end){
        int element=v[mid];
        if (element==target){
            index = mid;
            //left Search
            end=mid-1;
        }else if (element<target){
            //Right Search
            start=mid+1;
        }else if (element>target){
            //Left Search
            end=mid-1;
        }
        mid=start+(end-start)/2;
    }
    return index;
}

int main(){
    vector<int> v{1,5,8,9,9,9,9,9,9,15,19,24,25};

    cout<<occu(v,v.size(),9);
}