#include<iostream>
#include<string>

using namespace std;

bool areIsomorphic(string s1, string s2)
{
    int n1 = s1.size(), n2 = s2.size();
    if(n1 != n2)
        return false;
    
    int mp1[256] = {0};
    int mp2[256] = {0};
    
    for(int i = 0; i < n1; i++)
    {
        if(!mp1[s1[i]] && !mp2[s2[i]])
        {
            mp1[s1[i]] = s2[i];
            mp2[s2[i]] = s1[i];
        }
        else if(mp1[s1[i]] != s2[i])
            return false;
    }
    return true;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        string s1, s2;
        cin >> s1 >> s2;
        cout << areIsomorphic(s1, s2) << endl;
    }
    return 0;
}