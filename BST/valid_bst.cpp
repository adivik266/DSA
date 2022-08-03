#include<iostream>
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

bstnode* input_level()
{
    int val;
    cin>>val;
    bstnode* root=new bstnode(val);
    queue<bstnode*> q;
    q.push(root);

    while(!q.empty())
    {
        bstnode* temp=q.front();
        q.pop();

        int leftchild,rightchild;
        cin>>leftchild;
        if(leftchild!=-1)
        {
            bstnode* child=new bstnode(leftchild);
            q.push(child);
            temp->left=child;
        }
        cin>>rightchild;
        if(rightchild!=-1)
        {
            bstnode* child=new bstnode(rightchild);
            q.push(child);
            temp->right=child;
        }
    }
    return root;
}

void inorder(bstnode* root,vector<int> &arr)
{
    if(root==NULL)
    return;

    inorder(root->left,arr);
    arr.push_back(root->data);
    inorder(root->right,arr);
}

bool isbst_1(bstnode* root)
{
    vector<int> arr;
    inorder(root,arr);

    int prev=0,next=1;
    while(prev<next && next<arr.size())
    {
        if(arr[prev]<arr[next])
        {
            prev++;
            next++;
        }
        else
        return false;
    }
    return true;
}

bool helper(bstnode* root,int minv=INT_MIN,int maxv=INT_MAX)
{
    if(root==NULL)
    return true;

    bool left=helper(root->left,minv,root->data);
    bool right=helper(root->right,root->data,maxv);

    if(left && right && root->data>minv && root->data<maxv)
    return true;
    return false;
}

bool isbst_2(bstnode* root)
{
    return helper(root);
}

int main()
{
    bstnode* root=input_level();
    if(isbst_1(root))
    cout<<"BST";
    else
    cout<<"Not BST";

    cout<<endl;

    if(isbst_2(root))
    cout<<"BST";
    else
    cout<<"Not BST";
}