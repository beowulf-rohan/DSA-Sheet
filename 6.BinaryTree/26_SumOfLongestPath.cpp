#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};


// TC - O(n).... SC - O(ht)....
pair<int, int> sum(Node* root)
{
    if(root == NULL)
    {
        pair<int, int> p;
        p.first = 0;    p.second = 0;
        return p;
    }
    
    pair<int, int> l = sum(root->left);
    pair<int, int> r = sum(root->right);
    
    pair<int, int> ans;
    if(l.first == r.first)
    {
        ans.first = 1+l.first;      ans.second = max(l.second, r.second) + root->data;
        return ans;
    }
    
    else if(l.first > r.first)
    {
        ans.first = 1+l.first;      ans.second = l.second + root->data;
        return ans;
    }
    
    else 
    {
        ans.first = 1 + r.first;    ans.second = r.second + root->data;
        return ans;
    }
}

int sumOfLongRootToLeafPath(Node* root)
{
	pair<int, int> p = sum(root);
	return p.second;
}