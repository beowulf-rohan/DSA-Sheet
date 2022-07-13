#include <iostream>
#include <cmath>

using namespace std;

int sq(int n)
{
    int size = log2(n) + 1;
    int ans = 0;
    for (int i = 0; i < size; i++)
    {
        int setBit = (1 << i);
        if (setBit & n)
        {
            ans += (n << i);
        }
    }
    return ans;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << sq(n) << endl;
    }
}