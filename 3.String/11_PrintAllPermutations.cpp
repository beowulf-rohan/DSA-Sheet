#include<bits/stdc++.h>
using namespace std;

void permute(string S, int si, int ei, vector<string> &v)
{
	if(si == ei)
	{
	    v.push_back(S);
	    return;
	}
	for(int i = si; i <= ei; i++)
	{
	    swap(S[si], S[i]);
	    permute(S, si+1, ei, v);
	    swap(S[si], S[i]);
	}
}
	    
vector<string>find_permutation(string S)
{
	vector<string> v;
	permute(S, 0, S.size()-1, v);
	sort(v.begin(), v.end());
	return v;
}

int main()
 {
	int t;
	cin >> t;
	
	while(t--)
	{
	    string s;
	    cin >> s;
	    
        vector<string> v = find_permutation(s);
        for(int i = 0; i < v.size(); i++)
        {
            cout << v[i] << " ";
        }
        cout << endl;
	}
	return 0;
}