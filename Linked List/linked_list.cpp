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

void disp(node* head)
{
    while(head!=NULL)
    {
        cout<<head->data<<"->";
        head=head->next;
    }
    cout<<"NULL"<<endl;
}

void insert_at_tail(node* &head, int val)
{
    node *n = new node(val);

    if(head==NULL)
    {
        head=n;
        return;
    }
    node* temp=head;
    
    while(temp->next!=NULL)
    temp=temp->next;

    temp->next=n;
}

void insert_at_head(node* &head,int val)
{
    node *n = new node(val);
    n->next=head;
    head=n;
}

void insert_at_ith(node* &head,int i,int val)
{
    if(i==0)
    {
        insert_at_head(head,val);
        return;
    }

    node *n = new node(val);
    node *temp=head;
    for(int j=0;j<i-1;j++)
    temp=temp->next;

    n->next=temp->next;
    temp->next=n;
}

int length(node* head)
{
    int count=0;
    while(head)
    {
        count++;
        head=head->next;
    }
    return count;
}

int length_rec(node* head)
{
    if(head==NULL)
    return 0;
    return length_rec(head->next)+1;
}

void ith_node(node* head,int i)
{
    for(int j=0;j<i;j++)
    {
        if(head->next==NULL)
        {
            cout<<"NULL"<<endl;
            return;
        }
        else
        head=head->next;
    }
    cout<<head->data<<endl;
}

void delete_ith_node(node* &head,int i)
{
    if(i==0)
    {
        node* temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
        return;
    }
    node* temp=head;
    for(int j=0;j<i-1;j++)
    temp=temp->next;

    node* temp2=temp->next;
    temp->next=temp->next->next;

    temp2->next=NULL;
    delete temp2;
}

void delete_ith_node_from_end(node* &head,int i)
{
    node* first=head;
    node* second=head;

    for(int j=0;j<i+1;j++)
    first=first->next;

    if(first==NULL)
    {
        node* temp=head;
        head=head->next;
        delete temp;
        return;
    }

    while(first->next)
    {
        first=first->next;
        second=second->next;
    }

    node* temp=second->next;
    second->next=second->next->next;
    delete temp;
}

bool search(node* head,int val)
{
    while(head)
    {
        if(head->data==val)
        return true;
        head=head->next;
    }
    return false;
}

bool search_rec(node* head,int val)
{
    if(head==NULL)
    return false;
    if(head->data==val)
    return true;

    return search_rec(head->next,val);
}

node* middle(node* head)
{
    node* slow=head;
    node* fast=head;

    while(fast && fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;
    }

    return slow;
}

node* reverse(node* head)
{
    node* curr=head;
    node* prev=NULL;
    node* fwrd=curr;

    while(curr)
    {
        fwrd=fwrd->next;

        curr->next=prev;

        prev=curr;
        curr=fwrd;
    }

    return prev;
}

int main()
{
    node* head=NULL;
    
    insert_at_tail(head,1);
    insert_at_tail(head,2);
    insert_at_tail(head,3);
    insert_at_tail(head,4);
    insert_at_tail(head,9);
    
    insert_at_head(head,7);
    insert_at_head(head,5);
    insert_at_head(head,6);
    
    disp(head);
    
    cout<<"Length : "<<length(head)<<endl;

    cout<<"11th node : ";
    ith_node(head,11);

    insert_at_ith(head,2,100);
    disp(head);

    delete_ith_node(head,5);
    disp(head);

    cout<<"Length : "<<length_rec(head)<<endl;

    cout<<search(head,5)<<endl;

    cout<<search_rec(head,789)<<endl;

    cout<<"Middle : "<<middle(head)->data<<endl;

    delete_ith_node(head,6);
    disp(head);

    cout<<"Middle : "<<middle(head)->data<<endl;

    head=reverse(head);

    disp(head);

    delete_ith_node_from_end(head,6);

    disp(head);
}