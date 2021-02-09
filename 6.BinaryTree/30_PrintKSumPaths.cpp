#include<bits/stdc++.h>
#include<vector>

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

void kPaths(Node* root, int k, vector<int> &path)
{
    if(root == NULL)
        return;
    
    path.push_back(root->data);

    kPaths(root->left, k, path);
    kPaths(root->right, k, path);

    int sum = 0;
    for(int i = path.size()-1; i >= 0; i--)
    {
        sum += path[i];
        if(sum == k)
        {
            for(int j = i; j < path.size(); j++)
            {
                cout << path[j] << " ";
            }cout << endl;
        }
    }
    path.pop_back();
}

void printKPaths(Node* root, int k)
{
    vector<int> path;
    kPaths(root, k, path);
}