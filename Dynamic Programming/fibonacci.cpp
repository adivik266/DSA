#include<iostream>
using namespace std;

int fib(int n)       //  calls - 2^n  ,  O(2^n)
{
    if(n==0 || n==1)
    return n;

    return fib(n-1)+fib(n-2);
}

//Top-down DP

int fib2(int n,int *arr)        //  calls - 2n  ,  O(n)
{
    if(n==0 || n==1)
    return n;

    if(arr[n] != 0)
    return arr[n];

    int output = fib2(n-1,arr) + fib2(n-2,arr);
    arr[n]=output;  // store for future 
    return output;
}

//Bottom-up DP

int fib3(int n)           //  calls - n  ,  O(n)
{
    int *arr = new int[n+1];
    arr[0]=0;
    arr[1]=1;

    for(int i=2;i<n+1;i++)
    arr[i]=arr[i-1] + arr[i-2];

    int output = arr[n];
    delete []arr;
    return output;
}

int main()
{
    int n;
    cin>>n;

    int *arr = new int[n+1];
    for(int i=0;i<n+1;i++)
    arr[i]=0;

    cout<<fib3(n)<<endl;
    cout<<fib2(n,arr)<<endl;
    cout<<fib(n)<<endl;
}