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
            int* newarr=new int[2*cap];
            int j=0;
            for(int i=first;i<cap;i++)
            {
                newarr[j]=arr[i];
                j++;
            }
            for(int i=0;i<first;i++)
            {
                newarr[j]=arr[i];
                j++;
            }

            first=0;
            last=cap;
            cap*=2;
            delete []arr;
            arr=newarr;
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