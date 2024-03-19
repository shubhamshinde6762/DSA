#include <iostream>
#include <bits/stdc++.h>
using namespace std;

string remove_duplicate(string s){
    string ans="";
    int i=0;
    while(i<s.length()){
        if (ans.length()>0){
            if (ans[ans.length()-1]==s[i]){
                ans.pop_back();
            }else{
                ans.push_back(s[i]);
            }
        }else{
            ans.push_back(s[i]);
        }
        i++;
    }
    return ans;
}

int main(){
    cout<<remove_duplicate("cabbacda");
    return 0;
}