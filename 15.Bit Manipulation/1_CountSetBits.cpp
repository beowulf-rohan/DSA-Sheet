#include<iostream>
using namespace std;

int setBits(int N)
{
    int count = 0;
    {
        for (int i = 31; i >= 0; i--)
        {
            if ((N & (1 << i)) != 0)
                count++;
        }
    }
    return count;
}

int main()
{
    int n;
    cin >> n;

    cout << setBits(n);

    return 0;
}
