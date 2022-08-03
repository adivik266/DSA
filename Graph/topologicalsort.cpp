#include<bits/stdc++.h>
using namespace std;

void topologicalsort(vector<vector<int>> edges,int v,int e)
{
    int indegree[v]={0};
    for(int i=0;i<e;i++)
    indegree[edges[i][1]]++;

    queue<int> q;
    for(int i=0;i<v;i++)
    {
        if(indegree[i]==0)
        q.push(i);
    }

    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        cout<<u<<"->";
        for(int i=0;i<e;i++)
        {
            if(edges[i][0]==u)
            {
                indegree[edges[i][1]]--;
                if(indegree[edges[i][1]]==0)
                q.push(edges[i][1]);
            }
        }
    }
    cout<<"end";
}

int main()
{
    int v,e;
    cin>>v>>e;

    vector<vector<int>> matrix(e,vector<int>(2));

    for(int i=0;i<e;i++)
    {
        int fv,sv;
        cin>>fv>>sv;
        matrix[i][0]=fv;
        matrix[i][1]=sv;
    }

    topologicalsort(matrix,v,e);
}