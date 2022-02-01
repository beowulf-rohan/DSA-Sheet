#include<iostream>
#include<vector>

using namespace std;

//TC-O(n).... SC-O(n).....
int maxProfit(vector<int>& prices)
{
    int n = prices.size();
    if(n == 0)
        return 0;
        
    vector<int> left(n), right(n);
    left[0] = 0;    right[n-1] = 0;
    int lMin = prices[0], rMax = prices[n-1];
        
    for(int i = 1; i < n; i++)
    {
        lMin = min(prices[i], lMin);
        left[i] = max(left[i-1], prices[i]-lMin);
    }
        
    for(int i = n-2; i >= 0; i--)
    {
        rMax = max(rMax, prices[i]);
        right[i] = max(right[i+1], rMax-prices[i]);
    }
        
    int profit = max(left[n-1], right[0]);         //atMost 2 times... You can also sell one stock...  
                                                   //if you do so left[n-1] or right[0] stores profit.
    for(int i = 1; i < n; i++)
    {
        profit = max(profit, right[i]+left[i-1]);
    }
        
    return profit;
}


//TC-O(n).... SC-O(1).....
// int maxProfit(vector<int> prices)
// {
//     int profit = 0;
//     for(int i = 1; i < prices.size(); i++)
//     {
//         int sub = prices[i]-prices[i-1];
//         if(sub > 0)
//             profit += sub;
//     }
//     return profit;
// }


int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;

        vector<int> prices(n);
        for(int i = 0; i < n; i++)
        {
            cin >> prices[i];
        }

        cout << maxProfit(prices) << endl;
    }
    return 0;
}