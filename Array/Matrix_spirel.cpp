#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<vector<int> > v{{1,2,3,4},{5,6,7,8},{11,12,13,14}};

    int m=v.size();
    int n=v[0].size();

    int startrow=0;
    int startcol=0;
    int endrow=m-1;
    int endcol=n-1;

    int cnt=0;
    int total_ele=m*n;
    while (cnt<total_ele){
        for (int i=startcol; i<=endcol && cnt<total_ele ;i++){
            cout<<v[startrow][i]<<" ";
            cnt++;
        }
        startrow++;

        for (int i=startrow;i<=endrow && cnt<total_ele;i++){
            cout<<v[i][endcol]<<" ";
            cnt++;
        }
        endcol--;

        for (int i=endcol;i>=startcol && cnt<total_ele;i--){
            cout<<v[endrow][i]<<" ";
            cnt++;
        }
        endrow--;

        for (int i=endrow;i>=startrow && cnt<total_ele;i--){
            cout<<v[i][startcol]<<" ";
            cnt++;
        }
        startcol++;

    }
}