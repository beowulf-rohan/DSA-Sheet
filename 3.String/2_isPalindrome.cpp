#include<iostream>
#include<string>

using namespace std;

int isPlaindrome(string s)
{
	int i = 0, j = s.size()-1;
	while(i < j)
	{
	    if(s[i] != s[j])
	        return 0;
		i++;	j--;
	}
	return 1;
}


int main()
{
    string s;
    cin >> s;

    cout << isPlaindrome(s);

    return 0;
}