
#include<iostream>
#include<queue>
#include<vector>
#include<map>
using namespace std;

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};

    
Node *Merge(Node * p, Node * q)
{
    Node * res=new Node(-1);
    Node * end=res;
    while(p && q)
    {
        if(p->data<q->data)
        {
            end->bottom=p;
            end=end->bottom;
            p=p->bottom;
        }
        else
        {
            end->bottom=q;
            end=end->bottom;
            q=q->bottom;
        }
    }
    if(p!=NULL)end->bottom=p;
    else end->bottom=q;
    return res->bottom;
}
Node *flatten(Node *root)
{
   // Your code here
   if(root==NULL || root->next==NULL)
        return root;
    
    root->next=flatten(root->next);
    root=Merge(root,root->next);
    
    return root;
}