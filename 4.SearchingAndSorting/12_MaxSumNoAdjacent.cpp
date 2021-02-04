#include<iostream>
#include<algorithm>

using namespace std;

typedef long long int ll;


//TC - O(n).... SC - O(n)....
/*ll sumNoAdjacent(ll* arr, int n)
{
    ll dp[n];
    dp[0] = arr[0];
    dp[1] = max(arr[0], arr[1]);
    for(int i = 2; i < n; i++)
    {
        dp[i] = max(dp[i-1], dp[i-2]+arr[i]);
    }
    return dp[n-1];
}*/

//TC - O(n).... SC - O(1)....
int sumNoAdjacent(ll* arr, int n)
{
    int currIncluded = arr[0];
    int currExcluded = 0;
    int prevIncluded = currIncluded;
    int prevExcluded = currExcluded;

    for(int i = 1; i < n; i++)
    {
        currExcluded = max(prevIncluded, prevExcluded);
        currIncluded = prevExcluded + arr[i];

        prevExcluded = currExcluded;
        prevIncluded = currIncluded;
    }

    return max(currIncluded, currExcluded);
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;

        ll arr[n];
        for(int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        cout << sumNoAdjacent(arr, n) << endl;
    }
	return 0;
}