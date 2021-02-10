#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

unordered_map<string,int> mp;
vector<int> v;

string duplicates(Node* root)
{
    if(root == NULL)
        return "*";
    
    string s = to_string(root->data) + duplicates(root->left) + duplicates(root->right);
    
    
    if(mp[s] == 1)
        v.push_back(root->data);
    mp[s]++;
    return s;
}


void printAllDups(Node* root)
{
    mp.clear();     v.clear();
    
    duplicates(root);
    
    sort(v.begin(), v.end());
    
    for(int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    
    if(v.size() == 0)
        cout << -1;
}