#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void merge(int *arr, int start, int end, int mid){
    int lenleft = mid - start + 1;
    int lenright = end - mid;
    // Creating Two array Dynamically
    int *left = new int[lenleft];
    int *right = new int[lenright];

    for (int i = 0; i < lenleft; i++){
        left[i] = arr[i + start];
    }

    for (int i = 0; i < lenright; i++){
        right[i] = arr[i + mid + 1];
    }

    int i = 0, j = 0, k = start;   //as array saved only in segment

    while(i < lenleft && j < lenright){
        if (left[i] < right[j]){
            arr[k++] = left[i++];
        }else{
            arr[k++] = right[j++];
        }
    }
    while(i < lenleft)
        arr[k++] = left[i++];

    while(j < lenright)
        arr[k++] = right[j++];
}

void mergeSort(int *arr, int start, int end){
    // if only one element remain then exit
    if (start >= end)
        return;

    // devidind them into 2 parts
    int mid = start + (end - start) / 2;

    // recurring for left part
    mergeSort(arr, start, mid);

    // recurring for right part
    mergeSort(arr, mid + 1, end);

    // sorting the array
    merge(arr, start, end, mid);

}

int main(){
    int arr[] = {0,9,8,7,6,5,5,4,4,9,1,1,12,2,2};
    int n = 15;
    mergeSort(arr, 0, 14);
    for (auto i: arr) cout<<arr[i]<<endl;
    return 0;
}