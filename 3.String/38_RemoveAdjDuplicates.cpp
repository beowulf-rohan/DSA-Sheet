#include<iostream>
#include<string>
#include<stack>

using namespace std;

// TC - O(n)... SC - O(n)...
string removeConsecutiveCharacter(string S)
{
    stack<char> st;
    int n = S.size();
        
    st.push(S[n-1]);
    for(int i = n-2; i >= 0; i--)
    {
        if(st.top() != S[i])
            st.push(S[i]);
    }
        
    string ans = "";
    while(st.size() != 0)
    {
        ans += st.top();
        st.pop();
    }
    return ans;
}

// TC - O(n)... SC - O(1)...
string removeConsecutiveCharacter(string S)
{
    int n = S.size();
    if(n <= 1)
        return S;
    
    int j = 0;
    for (int i=1; i<n; i++) 
    {
        if (S[j] != S[i]) 
        { 
            j++;  
            S[j] = S[i];
        }
    }

    j++; 
    
    S.erase(S.begin()+j, S.end());      //for string....
    //S[j] = '\0';                      //for char array....
    return S;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;

        cout << removeConsecutiveCharacter(s) << endl;
    }
    return 0;
}