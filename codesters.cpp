//;compile c++ ```
#include<bits/stdc++.h>
using namespace std;

// void solve(string str, string &out)
// {
//     if(str.size() <= 1)
//     {
//         out += str;
//         return;
//     }
    
//     if(str[0] == str[1])
//     {
//         out += str[0];
//         out += '*';
//     }
//     else
//         out += str[0];
    
//     solve(str.substr(1), out);
// }

string pairStar(string str)
{
    if(str.size() <= 1)
        return str;
    
    string small = pairStar(str.substr(1));

    if(str[0] == str[1])
        return str[0] + "*" + small;
    else
        return str[0] + small;
}


int main()
{
    string str;
    cin >> str;

    cout << pairStar(str);

    return 0;
}//```