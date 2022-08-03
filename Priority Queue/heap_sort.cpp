//MIN HEAP

#include<bits/stdc++.h>
using namespace std;

class PriorityQueue
{
    vector<int> pq;

    public:

    PriorityQueue()
    {

    }

    bool isEmpty()
    {
        return pq.size()==0;
    }

    int getSize()
    {
        return pq.size();
    }

    int getMin()
    {
        if(isEmpty())
        return 0;

        return pq[0];
    }

    void insert(int ele)
    {
        pq.push_back(ele);   // CBT - yes, Heap - no
        int childIndex = pq.size()-1;

        while(childIndex > 0)
        {
            int parentIndex = (childIndex-1)/2;
            if(pq[childIndex] < pq[parentIndex])
            {
                swap(pq[childIndex],pq[parentIndex]);
                childIndex = parentIndex;
            }
            else
            break;
        }
    }

    int removeMin()
    {
        int ans = pq[0];
        swap(pq[0],pq[pq.size()-1]);
        pq.pop_back();  // CBT - yes, Heap - no

        int parentIndex = 0;
        while(true)
        {
            int leftchildIndex = 2*parentIndex + 1;
            int rightchildIndex = 2*parentIndex + 2;
            int minIndex = parentIndex;

            if(leftchildIndex < pq.size()  && pq[leftchildIndex] < pq[minIndex])
            minIndex = leftchildIndex;
            if(rightchildIndex < pq.size()  && pq[rightchildIndex] < pq[minIndex])
            minIndex = rightchildIndex;

            if(minIndex == parentIndex)
            break;

            swap(pq[parentIndex],pq[minIndex]);
            parentIndex=minIndex;
        }
        return ans;
    }
};

int main()
{
    PriorityQueue p;
    p.insert(100);
    p.insert(10);
    p.insert(15);
    p.insert(4);
    p.insert(17);
    p.insert(21);
    p.insert(67);

    cout<<p.getSize()<<endl;
    cout<<p.getMin()<<endl;

    while(!p.isEmpty())
    cout<<p.removeMin()<<" ";
}