#include<bits/stdc++.h>
using namespace std;

int prims(vector<vector <int>> edges,int v)
{
    int mst_wt=0;
    int parent[v],wt[v];
    bool visited[v];

    for(int i=0;i<v;i++)
    {
        parent[i]=-1;
        wt[i]=INT_MAX;
        visited[i]=false;
    }
    wt[0]=0;
    priority_queue<int,vector <int>, greater<int>> pq;

    for(int i=0;i<v;i++)
    pq.push(i);

    while(!pq.empty())
    {
        int u=pq.top();
        pq.pop();

        visited[u]=true;

        for(int i=0;i<v;i++)
        {
            if(edges[u][i]!=0)
            {
                if(visited[i]==false)
                {
                    if(edges[u][i]<wt[i])
                    {
                        wt[i]=edges[u][i];
                        parent[i]=u;
                    }
                }
            }
        }
    }

    for(int i=1;i<v;i++)
    {
        cout<<parent[i]<<"--"<<i<<endl;
        mst_wt+=wt[i];
    }

    return mst_wt;
}

int main()
{
    int v,e;
    cin>>v>>e;

    vector<vector <int>> matrix(v,vector<int>(v,0));

    for(int i=0;i<e;i++)
    {
        int fv,sv,w;
        cin>>fv>>sv>>w;
        matrix[fv][sv]=w;
        matrix[sv][fv]=w;
    }

    cout<<"Min Spanning Tree : "<<endl;
    int mst_wt = prims(matrix,v);

    cout<<"Weight of MST : "<<mst_wt;
}