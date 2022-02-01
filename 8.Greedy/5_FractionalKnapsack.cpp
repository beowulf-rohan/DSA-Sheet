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
    return maxValue;
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


#include<bits/stdc++.h>
using namespace std;
#define ll long long

class traits{
    public:
    ll a;
    ll b;
};

void solve(){
    int n; cin>>n;
    traits *arr = new traits[n];
    
    for(int i=0;i<n;i++){
        cin>>arr[i].a>>arr[i].b;
    }
    
    ll *health = new ll[n];
    for(int i=0;i<n;i++){
        health[i] = 0;
    }
    
    for(int i=0;i<n;i++){
        if(i==0){
            if(arr[i].a > arr[n-1].b){
                health[i] = arr[i].a - arr[n-1].b;
            }
            else
                health[i] = 0;
        }
        
        else{
            if(arr[i-1].b > arr[i].a){
                health[i] = 0;
            }
            else{
                health[i] = arr[i].a - arr[i-1].b;
            }
        }
    }
    
    
    
    ll first = INT_MAX;
    ll val = 0;
    int index = 0;
    
    for(int i=0;i<n;i++){
        val = arr[i].a - health[i];
        if(val < first){
            first = val;
            index = i;
        }
    }
    
    
    ll ans = 0;
    
    for(int i=0;i<n;i++){
        if(i==index){
            continue;
        }
        else{
            ans += health[i];
        }
    }

    cout<<ans + arr[index].a<<endl;
    
}


int main(){
    
    // write your code here
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}