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
int largestSumSubtreeSum(Node* root, int& ans)
{
    if(root == NULL)
        return 0;
    
    int currSum = root->data + largestSumSubtreeSum(root->left, ans) + largestSumSubtreeSum(root->right, ans);
    
    ans = max(currSum, ans);
    
    return currSum;
}

int largestSubtreeSum(Node* root)
{
	int ans = INT_MIN;
	largestSumSubtreeSum(root, ans);
	
	return ans;
}