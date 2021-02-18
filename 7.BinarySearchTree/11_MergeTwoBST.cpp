#include<iostream>
#include<vector>

using namespace std;


struct Node 
{
    int data;
    Node* right;
    Node* left;
    
    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};


// TC - O(n1+n2).... SC - O(n1+n2)....
void convertToLL(Node* root, Node* &head, Node* &prev)
{
    if(root == NULL)
        return;
    
    convertToLL(root->left, head, prev);
    
    if(head == NULL)
    {
        head = root;    prev = root;
    }
    else
    {
        prev->right = root;     prev->right->left = prev;
        prev = prev->right;
    }
    
    convertToLL(root->right, head, prev);
}

vector<int> merge(Node *root1, Node *root2)
{
    Node* head1 = NULL;
    Node* prev = NULL;
    convertToLL(root1, head1, prev);

    Node* head2 = NULL;
    prev = NULL;
    convertToLL(root2, head2, prev);
    
    vector<int> v;
    while(head1 != NULL && head2 != NULL)
    {
        if(head1->data <= head2->data)
        {
            v.push_back(head1->data);
            head1 = head1->right;
        }
        else
        {
            v.push_back(head2->data);
            head2 = head2->right;
        }
    }
    
    while(head1 != NULL)
    {
        v.push_back(head1->data);
        head1 = head1->right;
    }
    
    while(head2 != NULL)
    {
        v.push_back(head2->data);
        head2 = head2->right;
    }
    
    return v;
}