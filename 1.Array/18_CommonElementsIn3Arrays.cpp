#include <iostream>
#include <vector>

using namespace std;

vector<int> commonElements(int A[], int B[], int C[], int n1, int n2, int n3)
{
    vector<int> v;
    for (int i = 0, j = 0, k = 0; i < n1 && j < n2 && k < n3;)
    {

        if (A[i] == B[j] && B[j] == C[k])
        {
            if (v.size() == 0)
                v.push_back(A[i]);
            else if (v.back() != A[i])
                v.push_back(A[i]);
            i++;
            j++;
            k++;
        }
        else if (A[i] < B[j])
            i++;
        else if (B[j] < C[k])
            j++;
        else if (C[k] < A[i])
            k++;
    }
    return v;
}

int main()
{
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;

    int a[n1], b[n2], c[n3];
    for(int i = 0; i < n1; i++)
    {
        cin >> a[i];
    }
    for(int i = 0; i < n2; i++)
    {
        cin >> b[i];
    }
    for(int i = 0; i < n3; i++)
    {
        cin >> c[i];
    }

    vector<int> v = commonElements(a, b, c, n1, n2, n3);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }

    return 0;
}