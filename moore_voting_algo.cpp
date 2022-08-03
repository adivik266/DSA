//Majority element is element occuring more than n/2 times...

#include<iostream>
using namespace std;

int majority_ele(int arr[],int n)
{
    int cand=arr[0];
    int count=1;

    for(int i=1;i<n;i++)
    {
        if(arr[i]==cand)
        count++;
        else
        {
            count--;
            if(count==0)
            {
                cand=arr[i];
                count=1;
            }
        }
    }
    return cand;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];
    cout<<majority_ele(arr,n);
}