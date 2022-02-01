#include <bits/stdc++.h>
using namespace std;

int findMedianSortedArrays(const vector<int> &A, const vector<int> &B)
{
    int x = A.size(), y = B.size();
    if(x > y)
        return findMedianSortedArrays(B, A);
    
    int low = 0, high = x;
    while(low <= high)
    {
        int partX = (low+high)/2;
        int partY = (x+y+1)/2 - partX;
        
        int maxLX = (partX == 0 ? INT_MIN : A[partX-1]);
        int minRX = (partX == x ? INT_MAX : A[partX]);
        
        int maxLY = (partY == 0 ? INT_MIN : B[partY-1]);
        int minRY = (partY == y ? INT_MAX : B[partY]);
        
        if(maxLX <= minRY && maxLY <= minRX)
        {
            if((x+y)%2 == 0)
                return (double)(max(maxLX, maxLY) + min(minRX, minRY))/2;
            else
                return (double)max(maxLX, maxLY);
        }
        else if(maxLX > minRY)
        {
            high = partX-1;
        }
        else
        {
            low = partX+1;
        }
    }
}

int main()
{
    int n, m;
    cin >> m >> n;

    vector<int> A(m);
    vector<int> B(n);
    for (int i = 0; i < m; i++)
    {
        cin >> A[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> B[i];
    }

    cout << findMedianSortedArrays(A, B)  << endl;

    return 0;
}