#include<iostream>
#include<queue>
#include<vector>
#include<map>
using namespace std;
struct Node
{
    int data;
    Node* left, * right;
}; 

class Solution
{
    public:
    
    pair<bool,int> SumTree(Node * root)
    {
        if(root==NULL){
            pair<bool,int>ans= make_pair(true,0);
            return ans;
        }
        if(root->left ==NULL && root->right==NULL)
        {
           pair<bool,int> ans= make_pair(true,root->data);
            return ans;
        }
        
        pair<bool,int> l = SumTree(root->left);
        pair<bool,int> r = SumTree(root->right);
        bool cond = l.second+r.second==root->data?true:false;
        
        pair<bool,int> ans ;
        ans.first=false;
        if(root->data == l.second+r.second && l.first && l.first)
        {
        ans.second = l.second+r.second+root->data;
            ans.first=true;
        }
        return ans;
    
    }
    bool isSumTree(Node* root)
    {
         // Your code here
         return SumTree(root).first;
    }
};