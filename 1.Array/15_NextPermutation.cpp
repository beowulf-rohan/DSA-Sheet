#include<iostream>
#include<algorithm>
#include<vector>


using namespace std;

void solve(string s)
{
    string str = s;

    int n = s.size();
    int k;
    for(k = n-2; k >= 0; k--)
    {
        if(s[k] < s[k+1])
            break;
    }
        
    if(k < 0)
    {
        reverse(s.begin(), s.end());
    }
    else
    {
        int l;
        for(l = n-1; l > k; l--)
        {
            if(s[k] < s[l])
                break;
        }
        swap(s[k], s[l]);
        reverse(s.begin()+k+1, s.end());
    }

    if(s == str)
        cout << s << endl;
    else 
        cout << "no answer" << endl;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;

        vector<int> arr(n);
        for(int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }


    }
}