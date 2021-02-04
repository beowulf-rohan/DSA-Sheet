#include<iostream>
#include<string>

using namespace std;

string countAndSay(int n) 
{  
    if(n == 1)
        return "1";
    if(n == 2)
        return "11";
        
    string str = "11";
    for(int i = 3; i <= n; i++)
    {
        string temp = "";
        int count = 1;
           
        str = str + '&';                // So that you dont need a
                                        // special case for last index
        for(int j = 1; j < str.size(); j++)
        {
            if(str[j-1] == str[j])
            {
                count++;
            }
            else
            {
                temp = temp + to_string(count);
                temp = temp + str[j-1];
                count = 1;
            }
        }
        str = temp;
    }
    return str;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;

        cout << countAndSay(n) << endl;
    }
    return 0;
}