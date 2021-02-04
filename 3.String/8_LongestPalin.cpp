#include<iostream>
#include<string>

using namespace std;


//TC - O(n2)....  SC - O(1)....
void largestPalin(string s)
{
    int maxSize = 0;
    int low, high;
    for(int k = 0; k < s.size()-1; k++)
    {
        int i, j;
        
        //Odd Length...
        i = k;  j = k;
        while(i >= 0 && j < s.size() && s[i] == s[j])
        {
            int size = j-i+1;
            if(size > maxSize)
            {
                maxSize = size;
                low = i;    high = j;
            }
            i--;    j++;
        }
        
        //Even Length....
        i = k;  j = k+1;
        while(i >= 0 && j < s.size() && s[i] == s[j])
        {
            int size = j-i+1;
            if(size > maxSize)
            {
                maxSize = size;
                low = i;    high = j;
            }
            i--;    j++;
        }
    }
    
    for(int i = low; i <= high; i++)
    {
        cout << s[i];
    }cout << endl;
}

int main()
 {
	int t;
	cin >> t;
	while(t--)
	{
	    string s;
	    cin >> s;
	    
	    largestPalin(s);
	}
	return 0;
}