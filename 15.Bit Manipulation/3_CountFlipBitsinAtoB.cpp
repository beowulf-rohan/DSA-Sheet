#include<iostream>
using namespace std;

int countSetBits(int num)
{
    int count = 0, x = 1;
    
    for(int i = 31; i >= 0; i--)
    {
        if(num&(x<<i))
            count++;
    }
    return count;
}

int countBitsFlip(int a, int b)
{
    int XOR = a^b;
    return countSetBits(XOR);
}

int main()
{
    int a, b;
    cin >> a >> b;

    cout << countBitsFlip(a, b) << endl;
}