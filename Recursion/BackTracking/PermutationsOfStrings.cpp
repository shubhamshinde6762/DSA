#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void stringPermu(string&str,int i){
    // Base condn
    if (i >= str.length())
    {
        cout<<str<<endl;    
        return;
    }

    // Swapping and calling
    for(int j = i; j < str.length(); j++)
    {
        // swapping
        swap(str[i], str[j]);
        stringPermu(str, i + 1);
        // Backtracking Original String to avoid double call
        swap(str[i], str[j]);
    }
}

int main(){
    string str = "abc";
    stringPermu(str,0);
    return 0;
}