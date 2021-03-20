#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;


struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

unordered_map<Node*, int> mp;

int LISS(Node* root)
{
    if(!root)
        return 0;
    if(!root->left && !root->right)
        return 1;
    
    if(mp.find(root) != mp.end())
        return mp[root];
    
    int include = 1, notInclude = 0;
    
    notInclude = LISS(root->left) + LISS(root->right);
    
    include += (root->left) ? LISS(root->left->left) + LISS(root->left->right) : 0;
    include += (root->right) ? LISS(root->right->left) + LISS(root->right->right) : 0;

    return mp[root] = max(include, notInclude);
}