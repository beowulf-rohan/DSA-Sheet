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


// TC - O(n).... SC - O(n)....
unordered_map<Node*, int> mp;

int solve(Node* root)
{
    if(root == NULL)
        return 0;

    if(mp[root])
        return mp[root];
    
    int inc = root->data;
    if(root->left)
    {
        inc += solve(root->left->left) + solve(root->left->right);
    }
    if(root->right)
    {
        inc += solve(root->right->left) + solve(root->right->right);
    }


    int exc = solve(root->left) + solve(root->right);

    return mp[root] = max(inc, exc);
}

int getMaxSum(Node* root)
{
    return solve(root);
}


// TC - O(n).... SC - O(ht)....
pair<int, int> sum(Node* root)
{
    if(root == NULL)
    {
        pair<int, int> p;
        p.first = 0;    p.second = 0;
        return p;
    }

    pair<int, int> p1 = sum(root->left);
    pair<int, int> p2 = sum(root->right);

    pair<int, int> p;

    //root included... so take sum of childs excluded....
    p.first = root->data + p1.second + p2.second;
    //root excluded.... so take sum of childs max inc and exc...
    p.second = max(p1.first, p1.second) + max(p2.first, p2.second);

    return p;
}

int getMaxSum(Node* root)
{
    pair<int, int> p = sum(root);
    return max(p.first, p.second);
}