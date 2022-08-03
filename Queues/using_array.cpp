#include<iostream>
using namespace std;

class queue
{
    int *arr;
    int last=0;
    int first=-1;
    int s=0;
    int cap;
    public:

    queue()
    {
        cap=5;
        arr=new int[cap];
    }
    queue(int c)
    {
        cap=c;
        arr=new int[cap];
    }

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
        if(s==cap)
        {
            cout<<"Queue full"<<endl;
            return;
        }
        if(first==-1)
        first=0;

        arr[last]=ele;
        last=(last+1)%cap;
        s++;
    }

    void pop()
    {
        if(isEmpty())
        {
            cout<<"Queue empty"<<endl;
            return;
        }
        first=(first+1)%cap;
        s--;
    }

    int front()
    {
        if(isEmpty())
        {
            cout<<"Queue empty"<<endl;
            return -1;
        }   
        return arr[first];
    }
};

int main ()
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
}