#include <iostream>
#include <cmath>

using namespace std;

int sq(int n)
{
    int size = log2(n);
    int ans = 0, x = 1;
    for (int i = 0; i <= size; i++)
    {
        int setBit = (x << i);
        if (setBit & n)
        {
            ans += (n * (setBit));
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