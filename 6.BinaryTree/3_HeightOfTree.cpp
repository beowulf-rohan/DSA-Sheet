#include<iostream>
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


//TC - O(n)
int height(struct Node* node)
{
    if(node == NULL)
        return 0;
    return 1+max(height(node->left), height(node->right));
}
