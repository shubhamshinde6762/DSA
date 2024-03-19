#include <iostream>
#include <bits/stdc++.h>
using namespace std;

string remove_occurence(string str,string sub){
    int pos=str.find(sub);
    while(pos!=string::npos){
        str.erase(pos,sub.length());
        pos=str.find(sub);
    }
    return str;
}

int main(){
    cout<<remove_occurence("aabbabbab","ab");
    return 0;
}