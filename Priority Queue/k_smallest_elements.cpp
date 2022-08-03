#include<bits/stdc++.h>
using namespace std;

void k_smallest(int *arr,int n,int k)
{
    priority_queue<int> pq;

    for(int i=0;i<n;i++)
    {
        pq.push(arr[i]);
        if(pq.size() > k)
        pq.pop();
    }

    while(!pq.empty())
    {
        cout<<pq.top()<<" ";
        pq.pop();
    }
}

int main()
{
    int arr[] = {5,6,9,12,3,13,2};
    k_smallest(arr,7,3);
}