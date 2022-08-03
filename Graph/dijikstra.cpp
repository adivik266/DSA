#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> p;

void dijikstra(vector<vector<int>> edges,int src,int v,int e)
{
    int dist[v];
    bool visited[v];
    for(int i=0;i<v;i++)
    {
        dist[i]=INT_MAX;
        visited[i]=false;
    }
    dist[src]=0;

    priority_queue<p,vector<p>,greater<p>> pq;
    pq.push(make_pair(0,src));

    while(!pq.empty())
    {
        int u=pq.top().second;
        pq.pop();
        visited[u]=true;
        for(int i=0;i<v;i++)
        {
            if(edges[u][i]!=0)
            {
                if(visited[i]==false)
                {
                    if((dist[u] + edges[u][i])<dist[i])
                    {
                        dist[i]=dist[u]+edges[u][i];
                        pq.push(make_pair(dist[i],i));
                    }
                }
            }
        }
    }

    for(int i=0;i<v;i++)
    cout<<i<<" , Dist : "<<dist[i]<<endl;
}

int main()
{
    int v,e;
    cin>>v>>e;

    vector<vector<int>> matrix(v,vector<int>(v,0));

    for(int i=0;i<e;i++)
    {
        int fv,sv,w;
        cin>>fv>>sv>>w;
        matrix[fv][sv]=w;
        matrix[sv][fv]=w;
    }

    dijikstra(matrix,0,v,e);
}