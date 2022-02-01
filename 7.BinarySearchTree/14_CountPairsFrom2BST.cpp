#include<iostream>
#include<bits/stdc++.h>

using namespace std;


struct Node 
{
    int data;
    Node* right;
    Node* left;
    
    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};


// SC - O(n1+n2).... TC - O(n1+n2)....

void inorder(Node* root, vector<int> &v)
{
    if(root == NULL)
        return;
    
    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}

int countPair(vector<int> &a, vector<int> &b, int x)
{
    int count = 0;
    int i = 0, j = b.size()-1;
    while(i < a.size() && j >= 0)
    {
        if(a[i] + b[j] == x)
        {
            count++;
            i++;    j--;
        }
        else if(a[i] + b[j] > x)
        {
            j--;
        }
        else if(a[i] + b[j] < x)
        {
            i++;
        }
    }
    return count;
}

int countPairs(Node* root1, Node* root2, int x)
{
    vector<int> a, b;
    
    inorder(root1, a);
    inorder(root2, b);
    
    return countPair(a, b, x);
}

// SC - O(n1+n2).... TC - O(n1logn2)....
void inorder(Node* root, vector<int> &v)
{
    if(root == NULL)
        return;
    
    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}

bool check(vector<int> &v, int num)
{
    int si = 0, ei = v.size()-1;
    
    while(si <= ei)
    {
        int mid = (si+ei)/2;
        if(v[mid] == num)
            return true;
        
        if(v[mid] > num)
            ei = mid-1;
        else
            si = mid+1;
    }
    return false;
    
}

int countPair(vector<int> &a, vector<int> &b, int x)
{
    int count = 0;
    for(int i = 0; i < a.size(); i++)
    {
        int req = x-a[i];
        if(check(b, req))
            count++;
    }
    return count;
}

int countPairs(Node* root1, Node* root2, int x)
{
    vector<int> a, b;
    
    inorder(root1, a);
    inorder(root2, b);
    
    return countPair(a, b, x);
}

class Solution {
public:
    bool findTarget(Node* root, int k) 
    {
        stack <Node*> l, r;
        Node* curr = root;
        while(curr)
        {
            l.push(curr);
            curr = curr->left;
        }
        curr = root;
        while(curr)
        {
            r.push(curr);
            curr = curr->right;
        }
        
        while(l.top() != r.top())
        {
            int sum = l.top()->data + r.top()->data;
            if(sum == k)
                return true;
            else if(sum < k)
            {
                curr = l.top()->right;
                l.pop();
                while(curr)
                {
                    l.push(curr);
                    curr = curr->left;
                }
            }
            else
            {
                curr = r.top()->left;
                r.pop();
                while(curr)
                {
                    r.push(curr);
                    curr = curr->right;
                }
            }
        }
        
        return false;
    }
};