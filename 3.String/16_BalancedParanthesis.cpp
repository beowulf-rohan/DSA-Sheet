#include<iostream>
#include<string>
#include<stack>

using namespace std;

bool isBalanced(string str)
{
    stack<char> st;
    for(int i = 0; i < str.size(); i++)
    {
        if(str[i] == '(' || str[i] == '{' || str[i] == '[')
        {
            st.push(str[i]);
            continue;
        }
        
        if(st.size() == 0)
            return false;
        
        if(str[i] == ')')
        {
            char lastOpen = st.top();
            st.pop();
            if(lastOpen == '{' || lastOpen == '[')
                return false;
        }
        else if(str[i] == '}')
        {
            char lastOpen = st.top();
            st.pop();
            if(lastOpen == '[' || lastOpen == '(')
                return false;
        }
        else if(str[i] == ']')
        {
            char lastOpen = st.top();
            st.pop();
            if(lastOpen == '(' || lastOpen == '{')
                return false;
        }
    }
    return (st.size() == 0);
}

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        string s;
        cin >> s;

        cout << isBalanced(s) << endl;
    }
}