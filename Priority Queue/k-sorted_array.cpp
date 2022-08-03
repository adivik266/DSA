#include<iostream>
#include<queue>
using namespace std;

void k_sorted_array(int *arr,int n,int k)
{
    priority_queue<int> pq;
    
    for(int i=0;i<k;i++)
    pq.push(arr[i]);

    int s=0;
    for(int i=k;i<n;i++)
    {
        arr[s]=pq.top();
        pq.pop();
        s++;
        pq.push(arr[i]);
    }

    while(!pq.empty())
    {
        arr[s]=pq.top();
        pq.pop();
        s++;
    }
}

int main()
{
    int arr[] = {10,12,6,7,9};
    k_sorted_array(arr,5,3);

    for(int i=0;i<5;i++)
    cout<<arr[i]<<" ";
}