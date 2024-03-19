#include <iostream>
#include <vector>
using namespace std;

int PeakMountain(vector<int> &v,int size){
    int start=0;
    int end=size-1;
    int mid=start+(end-start)/2;


    while(start<end){            //Here < not <= because in line 17 we are not decreasing end by 1
        
        if (v[mid] < v[mid+1]){
            //Right Search
            start=mid+1;
        }else{
            end=mid;
        }

        mid=start+(end-start)/2;
    }
    return start;
}

int main(){
    vector<int> v{2,3,5,8,9,7,4,1};

    cout<<PeakMountain(v,v.size());
}