#include<iostream>
using namespace std;

int linear_search(int n,int arr[],int k)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i]==k)
        return i;
    }
    return -1;
}

int binary_search(int n,int arr[],int k)
{
    int s=0,e=n-1;
    while(s<=e)
    {
        int m=(s+e)/2;
        if(arr[m]==k)
        return m;
        else if(arr[m]>k)
        e=m-1;
        else
        s=m+1;
    }
    return -1;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];
    int k;
    cin>>k;

    int pos=binary_search(n,arr,k);
    cout<<pos;
}