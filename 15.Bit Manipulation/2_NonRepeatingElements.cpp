#include <iostream>
#include <vector>

using namespace std;

vector<int> singleNumber(vector<int> &nums)
{
    int Xor = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        Xor ^= nums[i];
    }

    int setBit = (Xor & (~(Xor - 1))); //Rightmost Set Bit

    int x = 0, y = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] & setBit)
            x ^= nums[i];
        else
            y ^= nums[i];
    }

    vector<int> v = {min(x, y), max(x, y)};
    return v;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector<int> v (2*n + 2);
        for (int i = 0; i < 2*n+2; i++)
        {
            cin >> v[i];
        }

        vector<int> ans = singleNumber(v);
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
    }
    return 0;
}