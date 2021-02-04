#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        unordered_map<int, int> mp;
        int m, n;
        cin >> m >> n;

        bool isTrue = true;
        for (int i = 0; i < m; i++)
        {
            int num;
            cin >> num;
            mp[num]++;
        }
        for (int i = 0; i < n; i++)
        {
            int num;
            cin >> num;
            if (mp[num] == 0)
            {
                isTrue = false;
            }
            else
            {
                mp[num]--;
            }
        }

        if (isTrue)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}