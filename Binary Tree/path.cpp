#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class btnode
{
    public:
    int data;
    btnode* left;
    btnode* right;

    btnode(int val)
    {
        data=val;
        left=NULL;
        right=NULL;
    }

};

void input_level(btnode* &root,int val)
{
    btnode* temp=new btnode(val);
    root=temp;
    queue<btnode*> q;
    q.push(root);

    while(!q.empty())
    {
        btnode* temp=q.front();
        q.pop();

        int leftchild,rightchild;
        cout<<"Enter left child of "<<temp->data<<endl;
        cin>>leftchild;
        if(leftchild!=-1)
        {
            btnode* child=new btnode(leftchild);
            q.push(child);
            temp->left=child;
        }
        cout<<"Enter right child of "<<temp->data<<endl;
        cin>>rightchild;
        if(rightchild!=-1)
        {
            btnode* child=new btnode(rightchild);
            q.push(child);
            temp->right=child;
        }
    }
}

bool path(btnode* root,int key,vector<int> &v)
{
    if(root==NULL)
    return false;

    v.push_back(root->data);
    if(root->data==key)
    return true;

    bool leftans=path(root->left,key,v);
    bool rightans=path(root->right,key,v);

    if(leftans||rightans)
    return true;

    v.pop_back();
    return false;
}

int main()
{
    btnode* root=NULL;
    input_level(root,1);

    vector<int> v;
    
    if(path(root,9,v))
    for(int i=0;i<v.size();i++)
    cout<<v[i]<<" ";
    else
    cout<<"Not Found";
}