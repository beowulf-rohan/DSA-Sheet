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


// TC - O(nlogn)... SC - O(logn)...
Node* buildTreeHelper(int* in, int* pre, int inS, int inE, int preS, int preE)
{
    if(inS>inE)
        return NULL;
    
    int rootData = pre[preS];
    int rootIndex = -1;
    for(int i = inS; i <= inE; i++)
    {
        if(in[i] == rootData)
        {
            rootIndex = i;
            break;
        }
    }
    
    int lInS = inS;
    int lInE = rootIndex-1;
    int rInS = rootIndex+1;
    int rInE = inE;
    
    int lPreS = preS+1;
    int lPreE = lInE-lInS+lPreS;
    int rPreS = lPreE+1;
    int rPreE = preE;
    
    Node* root = new Node(rootData);
    root->left = buildTreeHelper(in, pre, lInS, lInE, lPreS, lPreE);
    root->right = buildTreeHelper(in, pre, rInS, rInE, rPreS, rPreE);
    return root;
}

Node* buildTree(int in[],int pre[], int n)
{
    return buildTreeHelper(in, pre, 0, n-1, 0, n-1);
}



// TC - O(n)... SC - O(n)...
unordered_map<int, int> mp;

Node* buildTreeHelper(int* in, int* pre, int inS, int inE, int preS, int preE)
{
    if(inS>inE)
        return NULL;
    
    int rootData = pre[preS];
    int rootIndex = mp[rootData];
    
    int lInS = inS;
    int lInE = rootIndex-1;
    int rInS = rootIndex+1;
    int rInE = inE;
    
    int lPreS = preS+1;
    int lPreE = lInE-lInS+lPreS;
    int rPreS = lPreE+1;
    int rPreE = preE;
    
    Node* root = new Node(rootData);
    root->left = buildTreeHelper(in, pre, lInS, lInE, lPreS, lPreE);
    root->right = buildTreeHelper(in, pre, rInS, rInE, rPreS, rPreE);
    return root;
}

Node* buildTree(int in[],int pre[], int n)
{
    for(int i = 0; i < n; i++)
    {
        mp[in[i]] = i;
    }
    return buildTreeHelper(in, pre, 0, n-1, 0, n-1);
}