#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {

        if (s.length() != t.length())
            return 0;
        int hash[255] = {0};
        bool istChar[255] = {0};

        for (int i = 0; i < s.length(); i++)
        {
            if (hash[s[i]] == 0 && istChar[t[i]] == 0)
            {
                hash[s[i]] = t[i];
                istChar[t[i]] = 1;
            }
        }

        for (int i = 0; i < s.length(); i++)
        {
            if (t[i] != hash[s[i]])
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{

    return 0;
}