#include <iostream>
#include <bits/stdc++.h>
using namespace std;


void quickSort(int *arr, int start, int end)
{
    if (start >= end) return;

    // Partitioning starting from here
    int i = start;
    int j = start;
    
    while(j < end)
    {
        if (arr[j] < arr[end])   swap(arr[i++], arr[j]);
        j++;
    }
    
    swap(arr[i], arr[end]);
    // Partisioning end here
    quickSort(arr, start, i - 1);             //strictly neglect the ith element otherwise array sorted in descending order
    quickSort(arr, i + 1, end);
}

int main(){
    int arr[] = {8,7,6,5,4,3,2,1,0,9};
    quickSort(arr, 0, sizeof(arr)/sizeof(arr[0]) - 1);
    for (auto i : arr)
        cout << i << endl;
    return 0;
}