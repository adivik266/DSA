#include<iostream>
using namespace std;

void inplace_heapsort(int *arr, int n)
{
    //build heap - insert

    for(int i=1;i<n;i++)
    {
        int childIndex = i;
        while(childIndex > 0)
        {
            int parentIndex = (childIndex-1)/2;
            if(arr[childIndex] < arr[parentIndex])
            {
                swap(arr[parentIndex],arr[childIndex]);
                childIndex=parentIndex;
            }
            else
            break;
        }
    }

    //sort - removeMin

    int size=n;
    while(size>0)
    {
        swap(arr[0],arr[size-1]);
        size--;

        int parentIndex=0;
        while(true)
        {
            int leftchildIndex = 2*parentIndex + 1;
            int rightchildIndex = 2*parentIndex + 2;
            int minIndex = parentIndex;

            if(leftchildIndex<size && arr[leftchildIndex] < arr[minIndex])
            minIndex=leftchildIndex;

            if(rightchildIndex<size && arr[rightchildIndex] < arr[minIndex])
            minIndex=rightchildIndex;

            if(minIndex==parentIndex)
            break;

            swap(arr[minIndex],arr[parentIndex]);
            parentIndex=minIndex;
        }
    }
}

int main()
{
    int arr[]={5,1,2,0,8};
    inplace_heapsort(arr,5);

    for(int i=0;i<5;i++)
    cout<<arr[i]<<" ";

    return 0;
}