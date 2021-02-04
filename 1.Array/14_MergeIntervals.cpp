#include <iostream>
#include<algorithm>
#include <vector>

using namespace std;

bool compare(vector<int> v1, vector<int> v2)
{
    return v1[0] < v2[0];
}

vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    sort(intervals.begin(), intervals.end(), compare);

    vector<vector<int>> ans;
    ans.push_back(intervals[0]);

    for (int i = 1; i < intervals.size(); i++)
    {
        if (ans.back()[1] >= intervals[i][0])
            ans.back()[1] = max(ans.back()[1], intervals[i][1]);
        else
            ans.push_back(intervals[i]);
    }
    return ans;
}

int main()
{
    vector<vector<int>> intervals;
    vector<int> pair(2);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> pair[0] >> pair[1];
        intervals.push_back(pair);
    }

    vector<vector<int>> ans = merge(intervals);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i][0] << " " << ans[i][1] << endl;
    }

    return 0;
}