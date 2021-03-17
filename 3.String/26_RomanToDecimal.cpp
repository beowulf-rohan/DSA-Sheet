#include<bits/stdc++.h>
using namespace std;

int val(char ch)
{
    switch(ch)
    {
        case 'I' : return 1;
        case 'V' : return 5;
        case 'X' : return 10;
        case 'L' : return 50;
        case 'C' : return 100;
        case 'D' : return 500;
        case 'M' : return 1000;
    }
}

int romanToDecimal(string &str) 
{
    int n = str.size();
    int num = 0;
    for(int i = 0; i < n-1; i++)
    {
        int curr = val(str[i]);
        int after = val(str[i+1]);
        if(curr >= after)
            num += curr;
        else
            num -= curr;
    }
    num += val(str[n-1]);
    
    return num;
}