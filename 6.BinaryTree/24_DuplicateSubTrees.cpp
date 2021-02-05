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

unordered_map<string, int> mp;

string checkDuplicates(Node* root)
{
    if(root == NULL)
        return "*";
    if(root->left == NULL && root->right == NULL)
        return to_string(root->data);
    
    string s = "";
    s = to_string(root->data) + checkDuplicates(root->left) + checkDuplicates(root->right);
    
    mp[s]++;
    return s;
}

bool dupSub(Node *root)
{
    mp.clear();
    checkDuplicates(root);
    for(auto it = mp.begin(); it != mp.end(); it++)
    {
        if(it->second >= 2)
            return true;
    }
    return false;
}