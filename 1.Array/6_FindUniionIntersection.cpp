#include <iostream>
#include <unordered_set>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int a;
        unordered_set<int> mySet;

        for (int i = 0; i < n; i++)
        {
            cin >> a;
            mySet.insert(a);
        }
        for (int i = 0; i < m; i++)
        {
            cin >> a;
            mySet.insert(a);
        }
        cout << mySet.size() << endl;
    }
    return 0;
}