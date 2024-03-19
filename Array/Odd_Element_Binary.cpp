#include <iostream>
using namespace std;

int odd(int arr[],int size){
    int start=0;
    int end=size-1;
    int mid=start+(end-start)/2;

    while(start<=end){

        if (start==end){//Special Case if array contains only one element
            return mid;
        }
        if (mid%2==0){
            if (arr[mid]==arr[mid+1]){
                //Right Search
                start=mid+2;
            }else{
                //left Search
                end=mid;
            }
        }else{
            if (arr[mid]==arr[mid-1]){
                ////Right Search
                start=mid+1;
            }else{
                ///Left Search
            }
        }
        mid=start+(end-start)/2;
    }
    return -1;
}

int main(){
    int arr[]={1,1,2,2,3,3,4,4,3,6,6,4,4};
    int size=13;

    cout<<odd(arr,size);
}