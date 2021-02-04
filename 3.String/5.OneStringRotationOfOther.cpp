#include<bits/stdc++.h>
#include<string>

using namespace std;

bool stringRotation(string s1, string s2)
{
    string temp = s1+s1;
    return (temp.find(s2) == string::npos);
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;

    cout << stringRotation(s1, s2);

    return 0;
}