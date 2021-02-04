#include<iostream>
#include<cmath>

using namespace std;

int findPosition(int N)
{
    int size = log2(N) + 1;
    int count = 0, x = 1;
    for (int i = 0; i < size; i++)
    {
        if (N & (x << i))
            count++;
    }

    if (count == 1)
        return size;
    else
        return -1;
}

int main()
{
    int n;
    cin >> n;

    cout << findPosition(n) << endl;

    return 0;
}