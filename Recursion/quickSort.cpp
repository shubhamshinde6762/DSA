#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int partition(int *arr, int start, int end)
{
    int p = 0; // Position of Pivote element

    for (int i = start + 1; i <= end; i++)
    {
        if (arr[i] <= arr[start])
            p++;
    }

    // swapping pivote element to its right posn
    swap(arr[start], arr[start + p]);

    // checking right and left elements

    int i = start;
    int j = end;

    // Case : Two arises
    // A-> no need to swap
    // B-> require swapping for make left partitions smaller and right one grater than pivote index

    while (i < start + p && j > start + p)
    {
        while (arr[i] <= arr[start + p])
            i++;

        while (arr[j] > arr[start + p])
            j--;

        if (i < start + p && j > start + p)
        {
            swap(arr[i], arr[j]);
        }
    }

    return start + p; // returning pivote index
}

void quickSort(int *arr, int start, int end)
{
    // Base Condn
    if (start >= end)
        return;

    // doing partition
    int p = partition(arr, start, end);

    // doing again sorting two partitions
    quickSort(arr, start, p - 1);
    quickSort(arr, p + 1, end);
}

int main()
{

    int arr[] = {8,7,6,5,4,3,2,1,0,9};
    quickSort(arr, 0, 9);
    for (auto i : arr)
        cout << arr[i] << endl;
    return 0;
}