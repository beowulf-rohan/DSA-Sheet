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


// TC - O(N)... SC - O(ht of tree)....
int check(Node* root, bool &isTrue)
{
    if(root == NULL)
        return 0;
    int l = check(root->left, isTrue);
    int r = check(root->right, isTrue);
    
    if(abs(l-r) > 1)
        isTrue = false;
    return max(l,r)+1;
}

bool isBalanced(Node *root)
{
    bool isTrue = true;
    check(root, isTrue);
    return isTrue;
}
