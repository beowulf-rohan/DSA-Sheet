#include<bits/stdc++.h>
using namespace std;

string longestPalindrome(string s) 
    {
        int low = 0, high = 0;
        int maxLen = 0;
        for(int k = 0; k < s.size(); k++)
        {
            int i, j;
            //odd len....
            i = k;  j = k;
            while(i >= 0 && j < s.size() && s[i] == s[j])
            {
                int len = j-i+1;
                if(len > maxLen)
                {
                    maxLen = len;
                    low = i;    high = j;
                }
                i--;    j++;
            }
            //even len...
            i = k;  j = k+1;
            while(i >= 0 && j < s.size() && s[i] == s[j])
            {
                int len = j-i+1;
                if(len > maxLen)
                {
                    maxLen = len;
                    low = i;    high = j;
                }
                i--;    j++;
            }
        }
        
        string str = s.substr(low, high-low+1);
        return str;
    }