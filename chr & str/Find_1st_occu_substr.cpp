#include <iostream>
#include <bits/stdc++.h>
using namespace std;


// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/

class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.length();
        int n = needle.length();

        for (int i = 0; i <= m-n ; i++){
            for (int j = 0 ; j < n ;j++){
                if (haystack[i+j] != needle[j]){
                    break;
                }
                if (j==n-1) return i;
            }
                
        }
        return -1;
    }
};

int main(){
    
    return 0;
}