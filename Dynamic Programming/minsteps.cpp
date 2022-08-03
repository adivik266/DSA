/* min steps to reach 1, we can do :-
   n-1
   n/2 if (n%2==0)
   n/3 if (n%3==0)  */

#include<bits/stdc++.h>
using namespace std;

int minSteps(int n)
{
    if(n==1)
    return 0;

    int x = minSteps(n-1);
    int y = INT_MAX,z = INT_MAX;

    if(n%2==0)
    y = minSteps(n/2);
    if(n%3==0)
    z = minSteps(n/3);

    int ans = min(x,min(y,z)) + 1;
    return ans;
}

//Top-down DP / Memorisation

int helper(int n,int *arr)
{
    if(n==1)
    return 0;

    if(arr[n]!=-1)
    return arr[n];

    int x = helper(n-1,arr);
    int y = INT_MAX,z = INT_MAX;

    if(n%2==0)
    y = helper(n/2,arr);
    if(n%3==0)
    z = helper(n/3,arr);

    int ans = min(x,min(y,z)) + 1;
    arr[n] = ans;
    return ans;
}

int minSteps2(int n)
{
    int *arr = new int[n+1];
    for(int i=0;i<n+1;i++)
    arr[i]=-1;

    return helper(n,arr);
}

//Bottom-up DP

int minSteps3(int n)
{
    int *arr = new int[n+1];
    arr[0]=0;
    arr[1]=0;

    for(int i=2;i<n+1;i++)
    {
        int x = arr[i-1];
        int y = INT_MAX,z = INT_MAX;

        if(i%2==0)
        y = arr[i/2];
        if(i%3==0)
        z = arr[i/3];

        arr[i] = min(x,min(y,z)) + 1;
    }

    int ans = arr[n];
    delete []arr;
    return ans;
}

int main()
{
    int n;
    cin>>n;
    cout<<minSteps(n)<<endl;
    cout<<minSteps2(n)<<endl;
    cout<<minSteps3(n)<<endl;
}