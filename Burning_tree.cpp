//User function Template for C++
#include<iostream>
#include<queue>
#include<vector>
#include<map>
using namespace std;


struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
  public:
  Node * Mapping(Node * root, int target,map<Node * ,Node *>&CTP)
  {
      Node * res=NULL;
      if(root==NULL)
      return NULL;
       
       queue<Node *> q;
       q.push(root);
       CTP[root]=NULL;
       while(!q.empty())
       {
           Node * t= q.front();
           q.pop();
           if(t->left)
           {
               CTP[t->left]=t;
               q.push(t->left);
           }
           if(t->right)
           {
               CTP[t->right]=t;
               q.push(t->right);
           }
           if(t->data==target)
           {
               res=t;
           }
       }
       return res;
  }
  
  int Burn(Node * root,int target,map<Node*,Node*>CTP)
  {
      map<Node*,bool>visited;
      queue<Node*>q;
      
      q.push(root);
      visited[root]=true;
      int ans=0;
      while(!q.empty())
      {
          int f=0;
          int size=q.size();
         
         
          for(int i=0;i<size;i++)
          {
              Node * t= q.front();
              q.pop();
             
              if(t->left && !visited[t->left])
              {
                  visited[t->left]=1;
                  q.push(t->left);
                  f=1;
                  
              }
               if(t->right && !visited[t->right])
              {
                  visited[t->right]=1;
                  q.push(t->right);
                  f=1;
                 
              }
              if(CTP[t]&&!visited[CTP[t]])
              {
                  visited[CTP[t]]=1;
                  q.push(CTP[t]);
                  f=1;
                  
              }
          }
          if(f)ans++;
      }
      return ans;
  }
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        map<Node* ,Node*> ChildToParent;
        Node * start = Mapping(root,target,ChildToParent);
        
        int time=0;
       time= Burn(start,target,ChildToParent);
        return time;
    }
};