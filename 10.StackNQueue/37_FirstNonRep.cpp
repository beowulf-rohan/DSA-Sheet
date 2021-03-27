#include<bits/stdc++.h>
using namespace std;

string FirstNonRepeating(string A)
{
	string s = "";
	queue<char> q;
	int freq[26] = {0};		    
	
    for(int i = 0; i < A.size(); i++)
	{
		q.push(A[i]);
		freq[A[i] - 'a']++;
		while(q.size() != 0)
		{
		    if(freq[q.front() - 'a'] > 1)
		        q.pop();
		    else
		    {
		        s += q.front();
		        break;
		    }
	    }
	    if(q.size() == 0)
		    s += '#';
	}
	return s;
}