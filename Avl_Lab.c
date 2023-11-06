#include<stdio.h>
#include<stdlib.h>

typedef struct Node 
{
    struct Node * lchild;
    int data;
    int height;
    struct Node * rchild;
}node ;
  
  int isAVL =0;
int height(node * head)
{
    int lh,rh;
    lh=(lh=head && head->lchild?head->lchild->height:0);
    rh=(rh=head && head->rchild?head->rchild->height:0);

    return lh>rh?lh+1:rh+1;

}

node * LLRotation(node * p)
{
    
    node * pl=p->lchild;
    node *plr =pl->lchild;
  p->lchild=pl->rchild;
    pl->rchild=p;
    pl->lchild=plr;
    p->height=height(p);
    pl->height=height(pl);
   
        printf("LL Rotation");
    return pl;

}
node * RRRotation(node * p)
{
   
    node * pr =p->rchild;
    node * prl = pr->rchild;
    
    p->rchild=prl->lchild;
    pr->lchild=p;
    pr->rchild=prl;
    p->height=height(p);
    pr->height=height(p);
        printf("RR Rotation");
    return pr;
}

node * LRRotation(node * p)
{
    node * pl = p->lchild;
    node * plr = pl->rchild;
    pl->rchild=plr->lchild;
    p->lchild=plr->rchild;

    plr->lchild=pl;
    plr->rchild=p;

    plr->height=height(plr);
    pl->height=height(pl);
    p->height=height(p);

   
        printf("LR Rotation");
    return plr;
}
node * RLRotation(node * p)
{   
    node * pr = p->rchild;
    node * prl = pr->lchild;
    pr->lchild=prl->rchild;
    p->rchild=prl->lchild;

    prl->lchild=p;
    prl->rchild=pr;

    prl->height=height(prl);
    pr->height=height(pr);
    p->height=height(p);

    
    printf("RL Rotation");
    return prl;
}
int isBalanced(node * head)
{
    int lh,rh;
    lh=(lh=head && head->lchild?head->lchild->height:0);
    rh=(rh=head && head->rchild?head->rchild->height:0);

    return lh-rh;
}
node * rotation(node * head)
{  
        if(isBalanced(head)==2 || isBalanced(head)==-2)isAVL=1;
        if(isBalanced(head)==2 && (isBalanced(head->lchild)==1 || isBalanced(head->lchild)==0))
        {  
            return LLRotation(head);
        }
        if(isBalanced(head)==-2 && (isBalanced(head->rchild)==-1 || isBalanced(head->rchild)==0))
        {
            return RRRotation(head);
        }
        if(isBalanced(head)==2 && (isBalanced(head->lchild)==-1 || isBalanced(head->lchild)==0))
        {
            return LRRotation(head);
        }
         if(isBalanced(head)==-2 && (isBalanced(head->rchild)==1 || isBalanced(head->rchild)==0))
        {
          
            return RLRotation(head);
        }
        else return head;

}
node * Rinsert(node * head,int x)
{
    if(head==NULL)
    {
        node * temp = (node * )malloc(sizeof(node));
        temp->data=x;
        temp->height = 1;
        temp->lchild = NULL;
        temp->rchild = NULL;
        return temp;
    }
    else
    {
        if(head->data<x)head->rchild=Rinsert(head->rchild,x);
        if(head->data>x)head->lchild=Rinsert(head->lchild,x);
        head=rotation(head);
        head->height=height(head);
        return head;
    }
}

void preorder(node*p)
{
    if(p==NULL)return;
    else{
        printf("%d(%d) ",p->data,isBalanced(p));
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

int main()
{
int x;
node* root=NULL;
while(1)
{
    printf("Enter number to insert or -1 to exit : ");
    scanf("%d",&x);
    if(x==-1)break;
    else{
        root=Rinsert(root,x);
    }
}
printf("\n");
preorder(root);

}