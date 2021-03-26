#include<bits/stdc++.h>
using namespace std;

int numOfComputers(string s, int n)
{
    char seen[26];
    int ans = 0, occupied = 0;
    for(int i = 0; i < s.size(); i++)
    {
        int idx = s[i] - 'A';
        if(seen[idx] == 0)
        {
            seen[idx] = 1;      // arrived....
            if(occupied < n)
            {
                occupied++;
                seen[idx] = 2;  // alloted....
            }
            else
                ans++;
        }
        else
        {
            if(seen[idx] == 2)  // if alloted free one....
                occupied--;
            seen[idx] = 0;      // re-occur means left....
        }
    }
    return ans;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        string s;
        int n;
        cin >> s >> n;

        cout << numOfComputers(s, n) << endl;
    }
    return 0;
}