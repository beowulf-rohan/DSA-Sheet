#include<bits/stdc++.h>
#include<vector>

using namespace std;


//TC - O(e).... SC - O(e)....
// Stack - Queue implementation... Time
// taken is less as reversal is not done....
bool isMirror(vector<stack<int>> edges1, vector<queue<int>> edges2, int n, int e)
{
    for(int i = 0; i < n; i++)
    {
        stack<int> s = edges1[i];
        queue<int> q = edges2[i];
        while(s.size() != 0 && q.size() != 0)
        {
            if(s.top() != q.front())
                return false;
            s.pop();    q.pop();
        }
        if(s.size() != 0 || q.size() != 0)
            return false;
    }
    return true;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, e;
        cin >> n >> e;
        
        vector<stack<int>> edges1(n);
        vector<queue<int>> edges2(n);
        
        for(int i = 0; i < e; i++)
        {
            int f, s;
            cin >> f >> s;
            
            edges1[f-1].push(s-1);
        }
        
        for(int i = 0; i < e; i++)
        {
            int f, s;
            cin >> f >> s;
            
            edges2[f-1].push(s-1);
        }
        
        cout << isMirror(edges1, edges2, n, e) << endl;
        
    }
}


// TC - O(e).... SC - O(e)....
// Graph implementation... Time taken is
// more due to reversal operation....

bool isMirror(vector<int>* edges1, vector<int>* edges2, int n, int e)
{
    for(int i = 0; i < n; i++)
    {
        reverse(edges2[i].begin(), edges2[i].end());
    }
        
    for(int i = 0; i < n; i++)
    {
        if(edges1[i] != edges2[i])
            return false;
    }
    
    return true;
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, e;
        cin >> n >> e;
        
        vector<int>* edges1 = new vector<int>[n];
        vector<int>* edges2 = new vector<int>[n];
        for(int i = 0; i < e; i++)
        {
            int f, s;
            cin >> f >> s;
            edges1[f-1].push_back(s-1);
        }
        for(int i = 0; i < e; i++)
        {
            int f, s;
            cin >> f >> s;
            edges2[f-1].push_back(s-1);
        }
        
        cout << isMirror(edges1, edges2, n, e) << endl;
    }
    return 0;
}