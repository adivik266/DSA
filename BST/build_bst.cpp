#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class bstnode
{
    public:
    int data;
    bstnode* left;
    bstnode* right;

    bstnode(int val)
    {
        data=val;
        left=NULL;
        right=NULL;
    }
};

void print_level(bstnode* root)
{
    queue<bstnode*> q;
    q.push(root);
    while(!q.empty())
    {
        bstnode* temp=q.front();
        q.pop();

        cout<<temp->data<<" : ";
        if(temp->left)
        cout<<"L"<<temp->left->data<<" ";
        if(temp->right)
        cout<<"R"<<temp->right->data<<" ";
        cout<<endl;

        if(temp->left)
        q.push(temp->left);
        if(temp->right)
        q.push(temp->right);
    }
}

bstnode* helper(vector<int> arr, int s,int e)
{
    if(s>e)
    return NULL;

    int mid=(s+e)/2;
    int rootdata=arr[mid];

    bstnode* root=new bstnode(rootdata);
    root->left=helper(arr,s,mid-1);
    root->right=helper(arr,mid+1,e);

    return root;
}

bstnode* build(vector<int> arr)
{
    int n=arr.size();
    return helper(arr,0,n-1);
}

int main()
{
    int n;
    cin>>n;

    vector<int> arr;
    int inp;

    for(int i=0;i<n;i++)
    {
        cin>>inp;
        arr.push_back(inp);
    }

    bstnode* root=build(arr);
    print_level(root);
}