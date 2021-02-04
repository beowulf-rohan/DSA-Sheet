#include<iostream>
#include<string>
#include<cmath>
#include<stack>

using namespace std;

int countReversals(string s)
{
    if(s.size()%2 != 0)
        return -1;
    
    stack<char> st;
    int open = 0, close = 0;
    for(int i = 0; i < s.size(); i++)
    {
        //If curr is open... Push In stack...
        if(s[i] == '{')
        {
            st.push(s[i]);
            open++;
        }
        //If curr is closing... pop if stack not empty...
        //AND top is open....
        else if(s[i] == '}' && !st.empty() && st.top() == '{')
        {
            st.pop();
            open--;
        }
        //If curr is closing... stack is empty....
        //OR top is not open...
        else
            close++;
    }
    
    return ceil(1.0*open/2) + ceil(1.0*close/2);
}


int main()
 {
	int t;
	cin >> t;
	
	while(t--)
	{
	    string s;
	    cin >> s;
	    
	    cout << countReversals(s) << endl;
	}
	return 0;
}