#include<iostream>

using namespace std;

string sequence(string s, string* keypad)
{
    string output = "";
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == ' ')
        {
            output += "0";
        }
        else
        {
            int pos = s[i] - 'A';
            output += keypad[pos];
        }
    }
    return output;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;

        string keypad[] = {"2", "22", "222",
                            "3", "33", "333",
                            "4", "44", "444",
                            "5", "55", "555",
                            "6", "66", "666",
                            "7", "77", "777", "7777",
                            "8", "88", "888",
                            "9", "99", "999", "9999"
                          };
        
        cout << sequence(s, keypad) << endl;
    }
}