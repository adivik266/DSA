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

void disp(node* head)
{
    while(head!=NULL)
    {
        cout<<head->data<<"->";
        head=head->next;
    }
    cout<<"NULL"<<endl;
}

node* merge(node* head1,node* head2)
{
    if(head1==NULL)
    return head2;
    if(head2==NULL)
    return head1;

    node* nhead = NULL;

    if(head1->data < head2->data)
    {
        nhead=head1;
        head1=head1->next;
    }
    else
    {
        nhead=head2;
        head2=head2->next;
    }

    node* temp = nhead;

    while(head1 && head2)
    {
        if(head1->data < head2->data)
        {
            temp->next=head1;
            head1=head1->next;
        }
        else
        {
            temp->next=head2;
            head2=head2->next;
        }
        temp=temp->next;
    }

    if(head1)
    temp->next=head1;
    else if(head2)
    temp->next=head2;

    return nhead;
}

node* merge_rec(node* head1,node* head2)
{
    if(head1==NULL)
    return head2;
    if(head2==NULL)
    return head1;

    node* nhead=NULL;

    if(head1->data < head2->data)
    {
        nhead=head1;
        nhead->next=merge_rec(head1->next,head2);
    }
    else
    {
        nhead=head2;
        nhead->next=merge_rec(head1,head2->next);
    }

    return nhead;
}

node* sort(node* head)
{
    if(head==NULL || head->next==NULL)
    return head;

    node* slow=head;
    node* fast=head->next;

    while(fast && fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;
    }

    node* temp=slow->next;
    slow->next=NULL;

    return merge(sort(head),sort(temp));
}

int main()
{
    node* head1=NULL;
    node* head2=NULL;

    insert_at_tail(head1,1);
    insert_at_tail(head1,2);
    insert_at_tail(head1,4);
    disp(head1);

    insert_at_tail(head2,1);
    insert_at_tail(head2,3);
    insert_at_tail(head2,4);
    disp(head2);

    /*node* newhead = merge(head1,head2);
    disp(newhead);*/

    node* newhead2 = merge_rec(head1,head2);
    disp(newhead2);

    //SORTING

    node* head=NULL;
    insert_at_tail(head,5);
    insert_at_tail(head,6);
    insert_at_tail(head,3);
    insert_at_tail(head,7);
    insert_at_tail(head,2);
    insert_at_tail(head,1);
    disp(head);

    disp(sort(head));
}