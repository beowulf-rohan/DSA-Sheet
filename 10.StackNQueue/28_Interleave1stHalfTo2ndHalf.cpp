#include<bits/stdc++.h>
using namespace std;

bool interleave(queue<int> &q)
{
    if(q.size()%2 != 0)
        return false;

    // q : 1 2 3 4 5 6 7 8 9 10
    stack<int> st;
    int size = q.size()/2;

    // q : 6(f) 7 8 9 10    st : 5(t) 4 3 2 1
    for(int i = 0; i < size; i++)
    {
        st.push(q.front());
        q.pop();
    }

    // q : 6(f) 7 8 9 10 5 4 3 2 1      st : 
    while(st.size() != 0)
    {
        q.push(st.top());
        st.pop();
    }

    // q : 5(f) 4 3 2 1 6 7 8 9 10      st : 
    for(int i = 0; i < size; i++)
    {
        q.push(q.front());
        q.pop();
    }

    // q : 6(f) 7 8 9 10       st : 1(t) 2 3 4 5
    for(int i = 0; i < size; i++)
    {
        st.push(q.front());
        q.pop();
    }

    // q : 1(f) 6 2 7 3 8 4 9 5 10      st : 
    while(st.size() != 0)
    {
        q.push(st.top());
        st.pop();
        q.push(q.front());
        q.pop();
    }

    return true;

}

int main()
{
    int n;
    cin >> n;

    queue<int> q;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        q.push(x);
    }

    if(interleave(q))
    {
        while(q.size() != 0)
        {
            cout << q.front() << " ";
            q.pop();
        }
    }
    else 
        cout << "-1";
    return 0;
}