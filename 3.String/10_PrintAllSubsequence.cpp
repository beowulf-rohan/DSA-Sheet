#include<iostream>
#include<string>

using namespace std;

//for input "aaa" output should be "a", "aa", "aaa"
//for getting 100% correct answer use unordered_set

//TC - O(2^str.size())... SC - O(1)...

void print(string input, string output)
{
    if(input.size() == 0)
    {
        cout << output << endl;
        return;
    }

    print(input.substr(1), output);
    print(input.substr(1), input[0]+output);
}

void printAllSubs(string s)
{
    string input = s, output = "";
    print(input, output);
}

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        string s;
        cin >> s;
        printAllSubs(s);
    }
    return 0;
}