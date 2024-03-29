#include<iostream>
#include<string>

using namespace std;

int minFlips(string s)
{
    int c1 = 0, c2 = 0;
    for(int i = 0; i < s.size(); i++)
    {
        if(i%2 == 0 && s[i] == '1')
            c1++;
        else if(i%2 != 0 && s[i] == '0')
            c1++;
        
        if(i%2 == 0 && s[i] == '0')
            c2++;
        else if(i%2 != 0 && s[i] == '1')
            c2++;
    }
    
    return min(c1, c2);
}

int main()
 {
	int t;
	cin >> t;
	while(t--)
	{
	    string s;
	    cin >> s;
	    
	    cout << minFlips(s) << endl;
	}
	return 0;
}