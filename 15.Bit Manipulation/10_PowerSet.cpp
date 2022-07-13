#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<string> AllPossibleStrings(string s)
{
    vector<string> v;

    int size = 1 << s.size();
    for (int mask = 1; mask < size; mask++)
    {
        string str = "";
        for (int i = 0; i < 32; i++)
        {
            if (mask & (1 << i))
                str += s[i];
        }
        v.push_back(str);
    }
    sort(v.begin(), v.end());
    return v;
}

int main()
{
    string s;
    cin >> s;
    
    vector<string> str = AllPossibleStrings(s);
    for(int i = 0; i < str.size(); i++)
    {
        cout << str[i] << " ";
    }

    return 0;
}