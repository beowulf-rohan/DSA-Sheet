#include <iostream>

using namespace std;

int median(int *a, int *b, int m, int n)
{
    int size = (m+n);
    int m1 = 0, m2 = 0;
    int i = 0, j = 0;
    if(size%2 != 0)
    {
        for(int count = 0; count <= size/2; count++)
        {
            if(i < m && j < n)
                m1 = (a[i] < b[j]) ? a[i++] : b[j++];
            else if(i < m)
                m1 = a[i++];
            else if(j < n)
                m1 = b[j++];
        }
        return m1;
    }
    else
    {
        for(int count = 0; count <= size/2; count++)
        {
            m2 = m1;
            if(i < m && j < n)
                m1 = (a[i] < b[j]) ? a[i++] : a[j++];
            else if(i < m)
                m1 = a[i++];
            else if(j < n)
                m1 = b[j++];
        }
        return (m1+m2)/2;
    }
    
}

int main()
{
    int n, m;
    cin >> m >> n;

    int a[m], b[n];
    for (int i = 0; i < m; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    cout << median(a, b, m, n) << endl;

    return 0;
}