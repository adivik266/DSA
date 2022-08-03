#include<bits/stdc++.h>
using namespace std;

vector<int> remove_duplicates(int a[],int n)
{
    vector<int> output;
    unordered_map<int,bool> m;

    for(int i=0;i<n;i++)
    {
        if(m.count(a[i])==0)
        {
            output.push_back(a[i]);
            m[a[i]]=true;
        }
    }

    return output;
}

int main()
{
    int arr[] = {1,5,2,4,4,3,3,6,7,1,1,2};
    vector<int> output = remove_duplicates(arr,12);

    for(int i=0;i<output.size();i++)
    cout<<output[i]<<" ";
}