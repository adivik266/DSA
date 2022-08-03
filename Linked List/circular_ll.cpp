#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node* next;

    node(int val)
    {
        data=val;
        next=NULL;
    }
};

void insert_at_tail(node* &head,int val)
{
    node* n=new node(val);
    if(head==NULL)
    {
        head=n;
        n->next=head;
        return;
    }

    node* temp=head;
    while(temp->next!=head)
    temp=temp->next;

    temp->next=n;
    n->next=head;
}

void disp(node* head)
{
    node* temp=head;
    do
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }while(temp!=head);
    cout<<"NULL"<<endl;
}

int main()
{
    node* head=NULL;
    insert_at_tail(head,5);
    insert_at_tail(head,8);
    insert_at_tail(head,6);
    insert_at_tail(head,2);
    disp(head);
}