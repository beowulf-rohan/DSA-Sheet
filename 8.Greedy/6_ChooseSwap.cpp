#include<bits/stdc++.h>
using namespace std;

string chooseandswap(string a)
{
    set<char> mySet;
    for(int i = 0; i < a.size(); i++)
    {
        mySet.insert(a[i]);
    }
        
    for(int i = 0; i < a.size(); i++)
    {
        mySet.erase(a[i]);
        if(mySet.size() == 0)
            break;
        char ch1 = *mySet.begin();
        if(ch1 < a[i])
        {
            char ch2 = a[i];
            for(int j = 0; j < a.size(); j++)
            {
                if(a[j] == ch1)
                    a[j] = ch2;
                else if(a[j] == ch2)
                    a[j] = ch1;
            }
            break;
        }
    }
    return a;
}