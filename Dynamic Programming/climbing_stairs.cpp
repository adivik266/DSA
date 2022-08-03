/* climbing stairs problem
   either 1 or 2 steps
   distinct ways to climb to top */


#include<iostream>
using namespace std;

int climbstairs(int n)
{
    if(n==0 || n==1)
    return 1;

    return climbstairs(n-1)+climbstairs(n-2);
}

//DP

int climbstairs2(int n)
{
    int dp[n+1];
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<n+1;i++)
    dp[i]=dp[i-1]+dp[i-2];

    return dp[n];
}

// for k steps

int climbstairs3(int n,int k)
{
    int dp[n+1];
    dp[0]=1;

    for(int i=1;i<n+1;i++)
    {
        int ans=0;
        for(int jump=1;jump<=k;jump++)
        {
            if(i-jump >= 0)
            ans += dp[i-jump];
        }
        dp[i]=ans;
    }
    return dp[n];
}

int main()
{
    int n;
    cin>>n;
    cout<<climbstairs(n)<<endl;
    cout<<climbstairs2(n)<<endl;
    cout<<climbstairs3(n,2)<<endl;
}