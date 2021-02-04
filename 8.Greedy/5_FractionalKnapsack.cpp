#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


bool compare(Item a, Item b)
{
    double v1 = ((double)a.value/a.weight);
    double v2 = ((double)b.value/b.weight);
    
    return v1 > v2;
}

double fractionalKnapsack(int W, Item arr[], int n)
{
    sort(arr, arr+n, compare);
    
    double maxValue = 0;
    for(int i = 0; i < n; i++)
    {
        if(W >= arr[i].weight)
        {
            W -= arr[i].weight;
            maxValue += arr[i].value;
        }
        else
        {
            maxValue += ((double)W/arr[i].weight)*arr[i].value;
            break;
        }        
    }
}

int main()
{
	int t;
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--)
    {
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}

		cout<<fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
} 