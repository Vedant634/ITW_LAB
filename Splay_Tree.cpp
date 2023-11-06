#include<iostream>
#include<stdlib.h>
using namespace std;

class node 
{
    public:
    int value;
    node * left;
    node * right;
};
void preorder(node *);
node * insert(node * root,int data)
{
    node * head=root;
    if(head==NULL){
        node* temp = new node();
        temp->value=data;
        temp->right=NULL;
        return temp;
    }
    if(head->value>data)
    {
        head->left=insert(head->left,data);
    }
    else if(head->value<data)
    {
        head->right =insert(head->right,data);
    }
   
}




node * rRotate(node *p)
{
    node *q = p->left;
    p->left=q->right;
    q->right=p;
    cout<<"Zig";
    return q;
}

node* lRotate(node *p)
{
    node * q=p->right;
    p->right=q->left;
    q->left=p;
    cout<<"Zag";
    return q;
}

node* splay(node *root,int data)
{
  if(root==NULL || root->value==data)
  return root;

  if(root->value>data)
  {
    if(root->left==NULL)return root;
        //Zig-Zig (Right-Right)
    if(root->left->value>data)
    {
        root->left->left=splay(root->left->left,data);
        root = rRotate(root);
        cout<<"-";
        
    }
    // Zig-Zag(right-left)
    else if(root->left->value<data)
    {
        root->left->right=splay(root->left->right,data);
        if(root->left->right!=NULL)
        {
            root->left=lRotate(root->left);
            cout<<"-";
        }
        
        
    }
    if(root->left==NULL)return root;
        else return rRotate(root);
  }
  else{
    if(root->right==NULL)return root;
  //Zig-Zag (Right-Left)
    if(root->right->value>data)
    {
        root->right->left=splay(root->right->left,data);
        if(root->right->left!=NULL)
        {

            root->right = rRotate(root->right);
              cout<<"-";
        }
            
    }
    //Zag-Zag(Left-Left)
    else if (root->right->value<data)
    {
        
        root->right->right = splay(root->right->right,data);
        root = lRotate(root);
          cout<<"-";
        
    }
    
    if(root->right==NULL)
        return root;
    else
        return lRotate(root);
  }
}


node * search(node * root,int data)
{
    return splay(root,data);
}
void preorder(node * root)
{
    if(root!=NULL)
    {  
        cout<<root->value<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}
int main()
{
    node * root=NULL;
   
    cout<<"Enter number of elements : ";
    int n;
    cin>>n;
    int a[100];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        root=insert(root,a[i]);
    }
    // root=insert(root,25);
    // root=insert(root,36);
    // root=insert(root,30);c
    // root=insert(root,12);
    // root=insert(root,4);
    // root=insert(root,54);
    // root=insert(root,18);
    
  
    preorder(root);
    cout<<endl;
    cout<<"Enter number to search : ";
    int x;
    cin>>x;
    cout<<endl;
    cout<<"After searching : "<<endl;
    root=search(root,x);
    cout<<endl;
    preorder(root);
}