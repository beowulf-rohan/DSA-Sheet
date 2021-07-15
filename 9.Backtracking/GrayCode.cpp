#include<bits/stdc++.h>
using namespace std;

vector<string> getV(int A)
{
    if(A <= 0)
        return {"0"};
    if(A == 1)
        return {"0", "1"};

    vector<string> rec = getV(A-1);
    vector<string> v;
    for(int i = 0; i < rec.size(); i++)
    {
        v.push_back("0"+rec[i]);
    }
    for(int i = rec.size()-1; i >= 0; i--)
    {
        v.push_back("1"+rec[i]);
    }
    return v;
}

vector<int> grayCode(int A) 
{
    vector<string> bin = getV(A);

    vector<int> v;
    for(int i = 0; i < bin.size(); i++)
    {
        int num = stoi(bin[i], 0, 2);
        v.push_back(num);
        cout << num << " ";
    }
    return v;

}