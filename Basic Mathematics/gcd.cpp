#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
	public:
    int gcd(int A, int B) 
	{ 
	    // code here
	    if (A==0) return B;
	    if (B==0) return A;
	    
	   // GCD(a,b) = GCD (a-b,b)   a>b;
	   // GCD(a,b) = GCD (a,b-a)   b>a;
	    
	    while(A > 0 && B > 0){
	        if (A>B){
	            A=A-B;
	        }else{
	            B=B-A;
	        }
	    }
	    if (A==0) return B;
	    return A;
	    
	      
	} 
};


int main() 
{
   	int t;
    cin >> t;
    while (t--)
    {
        int A, B;
        cin >> A >> B;
        Solution ob;
       	cout <<  ob.gcd(A, B) << "\n";
    }
    return 0;
}
