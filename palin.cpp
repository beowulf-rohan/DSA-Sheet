#include<iostream>
using namespace std;

string solve(string str)
{
    int n = str.size();
    int i = 0, j = n-1;
    int temp = 0;
    while(i < j)
    {
        if(str[i] == str[j])
        {
            i++;    j--;
        }
        else
        {
            j = n-1;
            temp++;
            i = temp;
        }
    }

    for(int i = temp-1; i >= 0; i--)
    {
        str += str[i];
    }
    return str;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        string str;
        cin >> str;
        cout << solve(str) << endl;
    }
    return 0;
}

/*
aaaa
abba
amanaplanacanal
xyz
*/