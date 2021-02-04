#include<iostream>
#include<vector>

using namespace std;

int maxProfit(vector<int>& prices) 
{
    int minPrice = INT64_MAX;
    int maxProfit = 0;
    for(int i = 0; i < prices.size(); i++)
    {
        if (prices[i] < minPrice)
            minPrice = prices[i];
        else if (prices[i] - minPrice > maxProfit)
            maxProfit = prices[i] - minPrice;
    }
    return maxProfit;
}

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