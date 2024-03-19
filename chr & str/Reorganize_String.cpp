#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
using namespace std;

string reOrg(string &s){
    vector<char> v(26,0);
    char maxOccu;
    int maxOccuInt=INT_MIN;

    for (auto i:s)  v[i-'a']++;
    for (int i=0;i<v.size();i++) {
        if (maxOccuInt<v[i]){
            maxOccuInt=i;
            maxOccu=i;
        }
    }

    int j=0;
    while(j<s.length() && v[maxOccu]>0){
        s[j]=maxOccu+'a';
        j+=2;
        v[maxOccuInt]--;
    }

    if (maxOccuInt!=0){
        return "";
    }
    j=1;
    for (int i=0;i<v.size();i++){
        while(v[i]!=0){
            s[j]=i+'a';
            v[i]--;
            j+=2;
        }
    }
    return s;
}

// int main(){
//     cout<<reOrg("aaabc");
//     return 0;
// }