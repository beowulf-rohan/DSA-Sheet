#include<iostream>
#include<string>

using namespace std;

int count01(string s)
{
    int zero = 0, one = 0;
    int count = 0;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == '0')
            zero++;
        else
            one++;
        
        if(zero == one)
            count++;
    }
    if(zero != one)
        return -1;
    return count;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;

        cout << count01(s) << endl;
    }
}