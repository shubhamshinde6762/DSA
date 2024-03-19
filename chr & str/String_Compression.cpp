#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/string-compression/

class Solution {
public:
    int compress(vector<char>& chars) {
       int index = 0;
       int cnt = 1;
       int size = chars.size();
       

       for (int i = 1 ; i < size ; i++){
           if (chars[i] == chars[i-1]){
               cnt++;
           }else{
               chars[index++] = chars[i-1];
               if (cnt>1){
                   int start = index;
                   while(cnt){
                        chars[index++] = (cnt % 10) + '0';
                        cnt /= 10;
                   }
                    reverse(chars.begin() + s0tart,chars.begin() + index);
               }
                cnt = 1;
           }
       }
       chars[index++] = chars[size-1];
        if (cnt>1){
            int start = index;
            while(cnt){
                chars[index++] = (cnt % 10) + '0';
                cnt /= 10;
            }
            reverse(chars.begin() + start,chars.begin() + index);
        }

        return index; 
    }
};

int main(){
    
    return 0;
}