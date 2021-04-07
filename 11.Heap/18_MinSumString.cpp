#include<bits/stdc++.h>
using namespace std;

string sumOfStrings(string n1, string n2)
{
    if(n1.size() > n2.size())
        return sumOfStrings(n2, n1);
    string str = "";
        
    reverse(n1.begin(), n1.end());
    reverse(n2.begin(), n2.end());
        
    int l1 = n1.size(), l2 = n2.size();
        
    int sum = 0, carry = 0;
    for(int i = 0; i < l1; i++)
    {
        sum = (n1[i] - '0') + (n2[i] - '0') + carry;
        carry = sum/10;
            
        str.push_back(sum%10 + '0');
    }
        
    for(int i = l1; i < l2; i++)
    {
        sum = (n2[i] - '0') + carry;
        carry = sum/10;
        str.push_back(sum%10 + '0');
    }
        
    if(carry != 0)
    {
        str.push_back(carry + '0');
    }
        
    reverse(str.begin(), str.end());
        
    return str;
}
    
string solve(int arr[], int n) 
{
    sort(arr, arr+n);
        
    string n1 = "", n2 = "";
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == 0)
            continue;
        else if(n1.size() <= n2.size())
            n1 += to_string(arr[i]);
        else
            n2 += to_string(arr[i]);
    }
        
    return sumOfStrings(n1, n2);
}