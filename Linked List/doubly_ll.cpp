#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node* next;
    node* prev;

    node(int val)
    {
        data=val;
        next=NULL;
        prev=NULL;
    }
};

void disp(node* head)
{
    while(head!=NULL)
    {
        cout<<head->data<<"->";
        head=head->next;
    }
    cout<<"NULL"<<endl;
}

void insert_at_tail(node* &head,int val)
{
    node* n=new node(val);
    if(head==NULL)
    {
        head=n;
        return;
    }

    node* temp=head;
    while(temp->next)
    temp=temp->next;

    temp->next=n;
    n->prev=temp;
}

void delete_ith(node* &head,int i)
{
    node* temp=head;

    if(i==0)
    {
        head=head->next;
        head->prev=NULL;

        delete temp;
        return;
    }

    while(i--)
    temp=temp->next;

    temp->prev->next=temp->next;
    if(temp->next)
    temp->next->prev=temp->prev;

    temp->next=NULL;
    temp->prev=NULL;
    delete temp;
}

int main()
{
    node* head=NULL;
    insert_at_tail(head,3);
    insert_at_tail(head,7);
    insert_at_tail(head,9);
    insert_at_tail(head,1);
    insert_at_tail(head,5);
    disp(head);

    delete_ith(head,4);
    disp(head);
}