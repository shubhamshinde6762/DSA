#include <iostream>
#include <vector>
using namespace std;

pair<int,int> Binary_Search(vector<vector<int> > v, int target){

    int row=v.size();
    int col=v[0].size();
    int start=0;
    int end=row*col-1;
    int mid=start+(end-start)/2;

    while(start<=end){
        //i,j   element=c*i+j
        int i=mid/col;
        int j=mid%col;

        if (v[i][j]==target){
            return make_pair(i,j);
        }else if (v[i][j]<target){
            //Right Search
            start=mid+1;
        }else{
            //Left Search
            end=mid-1;
        }
        mid=start+(end-start)/2;
    }
    return make_pair(-1,-1);
}

int main(){
    vector<vector<int> > v{{1,2,3},{4,5,6},{7,8,9}};
    pair<int,int> result=Binary_Search(v,8);
    cout<<result.first<<" "<<result.second;
}