#include "llist.cpp"
#include<iostream>
using namespace std;

struct node
{
    T x;
    node *next;

};

llist::llist()
{
   node *head=NULL;
   node *temp,last;
   temp=head;
   last=head;
}


llist::push(T y)
{
    node *n=new node;
    n->x=y;
    n->next=Null;
    last->next=n;
    last=n;
}
llist::display()
{
    temp=head
    while(temp!=last)
    {
        cout<<temp->x<<' ';
        temp=temp->next;
    }
}





