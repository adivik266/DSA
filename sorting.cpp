#include <iostream>
#include <algorithm>
using namespace std;

void selection_sort(int n,int arr[])
{
    for(int i=0;i<n-1;i++)
    {
        int m=i;
        for(int j=i+1;j<n;j++)
        if(arr[j]<arr[m])
        m=j;

        swap(arr[m],arr[i]);
    }
}

void bubble_sort(int n,int arr[])
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1-i;j++)
        if(arr[j+1]<arr[j])
        swap(arr[j],arr[j+1]);
    }
}

void opt_bubble_sort(int n,int arr[])
{
    for(int i=0;i<n-1;i++)
    {
        int flag=0;
        for(int j=0;j<n-1-i;j++)
        if(arr[j+1]<arr[j])
        {
            swap(arr[j],arr[j+1]);
            flag=1;
        }

        if(flag==0)
        break;
    }
}

void insertion_sort(int n, int arr[])
{
    for(int i=1;i<n;i++)
    {
        int current=arr[i], j=i-1;
        while(arr[j]>current && j>=0)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=current;
    }
}

void merge(int arr[],int s,int m,int e)
{
    int n1=m-s+1, n2=e-m;
    int a[n1], b[n2];

    for(int i=0;i<n1;i++)
    a[i]=arr[s+i];
    for(int i=0;i<n2;i++)
    b[i]=arr[m+1+i];

    int i=0,j=0,k=s;

    while(i<n1 && j<n2)
    {
        if(a[i]<b[j])
        {
            arr[k]=a[i];
            i++;
            k++;
        }
        else
        {
            arr[k]=b[j];
            j++;
            k++;
        }
    }

    while(i<n1)
    {
        arr[k]=a[i];
        i++;
        k++;
    }

    while(j<n2)
    {
        arr[k]=b[j];
        j++;
        k++;
    }
}

void merge_sort(int arr[],int s,int e)
{
    if(s<e)
    {
        int m=(s+e)/2;
        merge_sort(arr,s,m);
        merge_sort(arr,m+1,e);
        merge(arr,s,m,e);
    }
}

int partition(int arr[],int s,int e)
{
    int pivot=arr[e];
    int i=s-1;
    for(int j=s;j<e;j++)
    {
        if(arr[j]<pivot)
        {
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[e]);
    return i+1;
}

void quick_sort(int arr[],int s,int e)
{
    if(s<e)
    {
        int m=partition(arr,s,e);

        quick_sort(arr,s,m-1);
        quick_sort(arr,m+1,e);
    }
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];

    quick_sort(arr,0,n-1);

    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
}