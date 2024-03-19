#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/divide-two-integers/

class Solution {
public:
    int divide(int dividend, int divisor) {
       if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }else if (dividend == INT_MIN && divisor == 1) {
            return INT_MIN;
        }

        if (dividend == 0) {
            return 0;
        }

        // Determine the sign of the result
        bool sign = (dividend > 0) ^ (divisor > 0);

        long long ldividend = llabs(static_cast<long long>(dividend));
        long long ldivisor = llabs(static_cast<long long>(divisor));

        long long temp = 0;
        int quotient = 0;

        for (int i = 31; i >= 0; --i) {
            if (temp + (ldivisor << i) <= ldividend) {     //checking whether MSB <= dividend
                temp += (ldivisor << i);                   //upadating temp
                quotient |= 1 << i;                       //Activating BIT
            }
        }

        return (sign) ? -quotient : quotient;
    }
};

int main(){
    
    return 0;
}