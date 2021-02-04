#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

void printSTL(string s)
{
    sort(s.begin(), s.end());
	   
    do
	{
	    cout << s << " ";
	}while(next_permutation(s.begin(), s.end()));
	    
	cout << endl;
}

void permute(string s, int si, int ei)
{
    if(si == ei)
    {
        cout << s << " ";
        return;
    }

    for(int i = si; i <= ei; i++)
    {
        swap(s[si], s[i]);     //swap      
        permute(s, si+1, ei);
        swap(s[si], s[i]);     //backtracking
    }
}

void printRecursive(string s)
{
    permute(s, 0, s.size()-1);
}

int main()
 {
	int t;
	cin >> t;
	
	while(t--)
	{
	    string s;
	    cin >> s;
	    
        printRecursive(s);
        //printSTL(s);
	}
	return 0;
}