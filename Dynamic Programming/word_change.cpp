/*  convert word1 to word2 with minimum steps:
    insert a character
    delete a character
    replace a character  */

#include<iostream>
using namespace std;

int md(string s1,int m,string s2,int n)
{
    if(m==0)
    return n;
    if(n==0)
    return m;
    if(s1[m-1]==s2[n-1])
    return md(s1,m-1,s2,n-1);

    int insert = md(s1,m,s2,n-1);
    int del = md(s1,m-1,s2,n);
    int replace = md(s1,m-1,s2,n-1);

    return 1+min(insert,min(del,replace));
}

int mindistance(string s1,string s2)
{
    return md(s1,s1.size(),s2,s2.size());
}

int mindistance2(string s1,string s2)
{
    int m=s1.size();
    int n=s2.size();
    int dp[m+1][n+1];

    for(int i=0;i<m+1;i++)
    {
        for(int j=0;j<n+1;j++)
        {
            if(i==0)
            dp[i][j]=j;
            else if(j==0)
            dp[i][j]=i;
            else if(s1[i-1]==s2[j-1])
            dp[i][j] = dp[i-1][j-1];
            else
            dp[i][j] = 1 + min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1]));
        }
    }
    return dp[m][n];
}

int main()
{
    string s1,s2;
    cin>>s1>>s2;
    cout<<mindistance(s1,s2)<<endl;
    cout<<mindistance2(s1,s2)<<endl;
}