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


// Recursive ...
void inOrder(Node* root)
{
    if(root == NULL)
        return;
    
    if(root->left)
        inOrder(root->left);
    
    cout << root->data << " ";
    
    if(root->right)
        inOrder(root->right);
}


// Iterative....
#include<stack>
void inOrder(Node* root)
{
    stack<Node*> st;
    Node* curr = root;
    while(!st.empty() || curr != NULL)
    {
        if(curr)
        {
            st.push(curr);
            curr = curr->left;
        }
        else
        {
            curr = st.top();
            st.pop();

            cout << curr->data << " ";
            curr = curr->right;
        }
    }
}