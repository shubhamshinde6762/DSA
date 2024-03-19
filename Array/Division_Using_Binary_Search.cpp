#include <iostream>
using namespace std;

double Division(int Dividend,int Divisor,int precision){
    int start=0;
    int end=abs(Dividend);
    int mid=start+(end-start)/2;

    int ans=-1;

    while(start<=end){
        if (abs(mid*Divisor)==abs(Dividend)){
            ans= mid;
            break;
        }else if (abs(mid*Divisor)>abs(Dividend)){
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
    for (int i = 0; i<precision;i++){
        for (double j=final;(j*Divisor)<Dividend;j+= step){
            final=j;
        }
        step/=10;
    }

    if ((Divisor<0 && Dividend<0) || (Divisor > 0 && Dividend > 0)){
        return final;
    };
    return 0-final;
}

int main(){
    int number;
    cin>>number;
    int num2;
    cin>>num2;
    int precision;
    cin>>precision;
    
    cout<<Division(number,num2,precision);
}