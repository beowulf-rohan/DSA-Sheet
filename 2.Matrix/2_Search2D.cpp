#include<bits/stdc++.h>
using namespace std;

// TC - O(lognm).... SC - O(1)....
bool searchMatrix(vector<vector<int>>& A, int B)
{
    int n = A.size(), m = A[0].size();
    int si = 0, ei = n*m - 1;
    while(si <= ei)
    {
        int mid = (si+ei)/2;
        int i = mid/m;
        int j = mid%m;
            
        if(A[i][j] == B)
            return 1;
        else if(A[i][j] > B)
            ei = mid-1;
        else
            si = mid+1;
    }
    return 0;
}