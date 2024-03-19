#include <iostream>
using namespace std;

int Binary_Search(int *arr,int size, int target){
    int start=0;
    int end=size-1;
    //int mid=(start+end)/2; To avoid Integer OverFlow Issues
    int mid= start+(end-start)/2;

    while(start<=end){
        int element=arr[mid];

        if (element==target){
            return mid;
        }else if (element<target){
            start=mid+1;
        }else{
            end=mid-1;
        }
        //mid=(start+end)/2; To avoid Integer OverFlow Issues
        mid= start+(end-start)/2;
    }
    return -1; //if target is not present in the arr;
}

int main(){
    int arr[]={1,3,4,6,7,9,11,13,16,18,20,21,23,24,25};
    int size= sizeof(arr)/sizeof(int);
    int target;
    cin>>target;

    int index = Binary_Search(arr,size,target);
    cout<<index;
}