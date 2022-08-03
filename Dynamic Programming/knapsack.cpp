#include<iostream>
using namespace std;

int knapsack(int n,int price[],int wts[],int W)
{
    if(n==0 || W==0)
    return 0;

    if(wts[n-1]>W)
    return knapsack(n-1,price,wts,W);
    else
    {
        int include = price[n-1] + knapsack(n-1,price,wts,W-wts[n-1]);
        int exclude = knapsack(n-1,price,wts,W);
        return max(include,exclude);
    }
}

int knapsack2(int n,int price[],int wts[],int W)
{
    int dp[n+1][W+1];
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<W+1;j++)
        {
            if(i==0 || j==0)
            dp[i][j]=0;
            else if(wts[i-1]>j)
            dp[i][j] = dp[i-1][j];
            else
            dp[i][j] = max(price[i-1]+dp[i-1][j-wts[i-1]],dp[i-1][j]);
        }
    }
    return dp[n][W];
}

int main()
{
    int price[] = {60,100,120};
    int wts[] = {10,20,30};
    int W = 50;
    cout<<knapsack(3,price,wts,W)<<endl;
    cout<<knapsack2(3,price,wts,W)<<endl;
}