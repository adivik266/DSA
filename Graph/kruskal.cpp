#include<bits/stdc++.h>
using namespace std;

void makeset(int v,int parent[])
{
    for(int i=0;i<v;i++)
    parent[i]=i;
}

int find(int i,int parent[])
{
    while(parent[i]!=i)
    i=parent[i];

    return i;
}

void merge(int ra,int rb,int parent[])
{
    parent[rb]=ra;
}

bool cmp(vector<int> A,vector<int> B)
{
    return A[2]<B[2];
}

int kruskal(vector<vector <int>> edges,int v,int e)
{
    int mst_wt=0;
    sort(edges.begin(),edges.end(),cmp);

    int parent[v];
    makeset(v,parent);
    for(int i=0;i<e;i++)
    {
        int a=edges[i][0];
        int b=edges[i][1];
        int ra=find(a,parent);
        int rb=find(b,parent);
        
        if(ra!=rb)
        {
            cout<<a<<"--"<<b<<endl;
            merge(ra,rb,parent);
            mst_wt+=edges[i][2];
        }
    }
    
    return mst_wt;
}

int main()
{
    int v,e;
    cin>>v>>e;

    vector<vector <int>> matrix(e,vector<int>(3,0));

    for(int i=0;i<e;i++)
    {
        int fv,sv,w;
        cin>>fv>>sv>>w;
        matrix[i][0]=fv;
        matrix[i][1]=sv;
        matrix[i][2]=w;
    }

    cout<<"Min Spanning Tree : "<<endl;
    int mst_wt = kruskal(matrix,v,e);

    cout<<"Weight of MST : "<<mst_wt;
}