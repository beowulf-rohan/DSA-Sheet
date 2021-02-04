#include<iostream>
#include<string>
#include<vector>

using namespace std;

string longestCommonPrefix(vector<string>& str)
{
    int minLen = 201;  //200 maxLen of input (given)
    string s = "";
    for(int i = 0; i < str.size(); i++)
    {
        if(str[i].size() < minLen)
        {
            minLen = str[i].size();
            s = str[i];
        }
    }
        
    int count = 0;
    for(int i = 0; i < minLen; i++)
    {
        for(int j = 0; j < str.size(); j++)
        {
            if(str[j][i] != s[i])
                return s.substr(0, count);
        }
        count++;
    }
    return s.substr(0, count);
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;

        vector<string> str(n);
        for(int i = 0; i < n; i++)
        {
            cin >> str[i];
        }

        cout << longestCommonPrefix(str) << endl;
    }
    return 0;
}