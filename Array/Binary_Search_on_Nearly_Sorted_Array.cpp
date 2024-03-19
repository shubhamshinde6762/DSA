#include <iostream>
using namespace std;

int Binary_Search(int *arr,int size, int target){
    int start=0;
    int end=size-1;
    //int mid=(start+end)/2; To avoid Integer OverFlow Issues
    int mid= start+(end-start)/2;

    while(start<=end){

        if (target==arr[mid])
        {
            return mid;
        }
        else if(target==arr[mid-1])
        {
            return mid -1;
        }
        else if(target==arr[mid+1])
        {
            return mid+1;
        }
        else if (arr[mid]<target)
        {
            start=mid+2;   //Checked mid and mid+1
        }
        else{
            end=mid-2;     //Checked mid and mid-1
        }
        //mid=(start+end)/2; To avoid Integer OverFlow Issues
        mid= start+(end-start)/2;
    }
    return -1; //if target is not present in the arr;
}

int main(){
    int arr[]={10,3,40,20,50,80,70};
    int size= sizeof(arr)/sizeof(int);
    int target=70;

    int index = Binary_Search(arr,size,target);
    cout<<index;
}