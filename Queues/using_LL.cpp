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

class queue
{
    node* head=NULL;
    node* tail=NULL;
    int s=0;
    public:

    int size()
    {
        return s;
    }

    bool isEmpty()
    {
        return s==0;
    }

    void push(int ele)
    {
        node* n=new node(ele);
        if(head==NULL)
        {
            head=n;
            tail=n;
            s++;
            return;
        }
        tail->next=n;
        tail=n;
        s++;
    }

    void pop()
    {
        if(isEmpty())
        {
            cout<<"Queue empty"<<endl;
            return;
        }
        node* temp=head;
        head=head->next;
        delete temp;
        s--;
    }

    int front()
    {
        if(isEmpty())
        {
            cout<<"Queue empty"<<endl;
            return -1;
        }
        return head->data;
    }
};

int main()
{
    queue q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    q.push(70);
    cout<<q.front()<<endl;
    q.pop();
    q.pop();
    q.pop();
    cout<<q.front()<<endl;
    cout<<q.size()<<endl;
    cout<<q.isEmpty()<<endl;
    q.push(60);
    q.push(70);

    q.pop();
    q.pop();
    cout<<q.front()<<endl;
    cout<<q.size()<<endl;

    while(!q.isEmpty())
    {
        cout<<q.front()<<endl;
        q.pop();
    }
    cout<<q.size()<<endl;
    cout<<q.isEmpty()<<endl;
}