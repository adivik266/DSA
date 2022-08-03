#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void dfs_helper(vector<vector<int>> matrix,int sv,vector<bool> &visited)
{
    cout<<sv<<" ";
    visited[sv] = true;
    int n=matrix.size();
    for(int i=0;i<n;i++)
    {
        if(matrix[sv][i]==1 && visited[i]==false)
        dfs_helper(matrix,i,visited);
    }
}

void dfs(vector<vector<int>> matrix)
{
    int n=matrix.size();
    vector<bool> visited(n,false);
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            count++;
            dfs_helper(matrix,i,visited);
        }
    }
    cout<<endl;
    cout<<"Connected components : "<<count;
}

void bfs_helper(vector<vector <int>> matrix,int sv,vector<bool> &visited)
{
    int n=matrix.size();
    queue<int> q;
    q.push(sv);
    visited[sv]=true;
    while(!q.empty())
    {
        int temp=q.front();
        q.pop();
        cout<<temp<<" ";
        for(int i=0;i<n;i++)
        {
            if(matrix[temp][i] && !visited[i])
            {
                q.push(i);
                visited[i]=true;
            }
        }
    }
}

void bfs(vector<vector <int>> matrix)
{
    int n=matrix.size();
    vector<bool> visited(n,false);
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            count++;
            bfs_helper(matrix,i,visited);
        }
    }
    cout<<endl;
    cout<<"Connected components : "<<count;
}

int main()
{
    int n,e;
    cin>>n>>e;

    vector<vector <int>> matrix(n,vector<int>(n,0));

    for(int i=0;i<e;i++)
    {
        int fv,sv;
        cin>>fv>>sv;
        matrix[fv][sv]=1;
        matrix[sv][fv]=1;
    }
    cout<<"DFS : ";
    dfs(matrix);
    cout<<endl;
    cout<<"BFS : ";
    bfs(matrix);
    cout<<endl;
}