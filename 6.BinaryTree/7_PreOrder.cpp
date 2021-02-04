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


//Recursive...
void preorder(Node* root)
{
    if(root == NULL)
        return;
    
    cout << root->data << " ";
    
    preorder(root->left);
    preorder(root->right);
}


//Iterative...
#include<stack>
void preOrder(Node* root)
{
    if(root == NULL)
        return;
   
   stack<Node*> st;
   st.push(root);
   
   while(!st.empty())
   {
       Node* curr = st.top();
       st.pop();
       
       cout << curr->data << " ";

       if(curr->right)
        st.push(curr->right);
       
       if(curr->left)
        st.push(curr->left);
   }
}