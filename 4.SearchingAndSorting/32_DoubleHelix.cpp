#include <iostream>
using namespace std;

int main()
{
	while(true)
	{
		int n;
		cin >> n;
		
		if(n == 0)
			break;
		
		int a[n];
		for(int i = 0; i < n; i++)	cin >> a[i];
		
		int m;
		cin >> m;
		int b[m];
		for(int i = 0; i < m; i++)	cin >> b[i];
		
		int i = 0, j = 0;
		int sum = 0;
		int s1 = 0, s2 = 0;
		
		while(i < n && j < m)
		{
			if(a[i] < b[j])
				s1 += a[i++];
			else if(a[i] > b[j])
				s2 += b[j++];
			else
			{
				sum = sum + max(s1, s2) + a[i];
				s1 = 0;		s2 = 0;
				i++;	j++;
			}
		}
		while(i < n)
		{
			s1 += a[i++];
		}
		while(j < m)
		{
			s2 += b[j++];
		}
		
		sum = sum + max(s1, s2);
		
		cout << sum << endl;
	}
	return 0;
}