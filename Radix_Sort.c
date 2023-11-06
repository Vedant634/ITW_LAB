#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
   struct node * next;
}node ;

int MaxDigits(int a[],int n)
{
    int max=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]>max)max=a[i];
    }
    int cnt=0;
    while(max)
    {  
       max/=10;
        cnt++;
    }
    return cnt;
}

int Digit(int n,int d)
{
   return (n/d)%10;
}

node * Insert(node * head,int data)
{
    node * temp=(node *)malloc(sizeof(node));
    temp->data=data;
    temp->next=NULL;
    if(head==NULL)
    {
        head=temp;
    }
    else
    {
       node *t = head;
    while(t->next!=NULL)
    {
        t=t->next;
    }
    t->next=temp;
    
    }
    return head;
}
node * dlt(node * head)
{
    node * temp=head->next;
    free(head);
    return temp;
}
int Delete(node *b[],int n)
{
    int x=0;
    for(int i=0;i<10;i++)
    {
        if(b[i]!=NULL)
        {
            x=b[i]->data;
            b[i]=dlt(b[i]);
            break;
        }
    }
    return x;
}

int main()
{
    int a[10]={21203,4523,823,7839,4235,9823,132,78,4801,665};
    int mxd=MaxDigits(a,10);
    int x=0;
    static int d=1;
    node *b[10];
   
  
    for(int i=0;i<10;i++)
    {
        b[i]=NULL;
    }
    for(int i=0;i<mxd;i++)
    {   
        for(int j=0;j<10;j++)
        {
        x=Digit(a[j],d);
        b[x]=Insert(b[x],a[j]);
        }
        for(int i=0;i<10;i++)
        {
            a[i]=Delete(b,10);
        }
        d*=10;
    }
       for(int i=0;i<10;i++)
    {
        printf("%d ",a[i]);
    }
    

}