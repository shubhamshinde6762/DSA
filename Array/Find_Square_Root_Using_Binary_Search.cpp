#include <iostream>
using namespace std;

double SqNumber(int n,int p){
    int start=1;
    int end=n;
    int mid=start+(end-start)/2;

    int ans=-1;

    while(start<=end){
        if ((mid*mid)==n){
            ans= mid;
            break;
        }else if ((mid*mid)>n){
            end=mid-1;
        }else{
            start=mid+1;
            ans=mid;
        }
        mid=start+(end-start)/2;
    }
    

    //ONLY INT number has been discovered;

    // for Precision
    double final=ans;
    double step=0.1;
    for (int i = 0; i<p;i++){
        for (double j=final;(j*j)<n;j+= step){
            final=j;
        }
        step/=10;
    }
    return final;
}

int main(){
    int number;
    cin>>number;
    int precision;
    cin>>precision;
    
    cout<<SqNumber(number,precision);
}