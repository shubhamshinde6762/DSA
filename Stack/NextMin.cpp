#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> v{2,1,4,3};
    stack<int> st;
    st.push(-1);
    int arr[4] = {0,0,0,0};
    for (int i = v.size() - 1; i >= 0; i--)
    {
        while(st.top() >= v[i])
        {
            st.pop();
        }
        arr[i] = st.top();
        st.push(v[i]);

    }

    for (auto i : arr) cout<<i<<endl;
    return 0;
}