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

void print_level(bstnode* root)
{
    queue<bstnode*> q;
    q.push(root);
    while(!q.empty())
    {
        int n=q.size();

        while(n)
        {
            bstnode* temp=q.front();
            q.pop();

            cout<<temp->data<<" ";
            if(temp->left)
            q.push(temp->left);
            if(temp->right)
            q.push(temp->right);

            n--;
        }
        cout<<endl;
    }
}

bool search(bstnode* root, int val)
{
    if(root==NULL)
    return false;

    if(root->data==val)
    return true;

    if(val>root->data)
    return search(root->right,val);
    else
    return search(root->left,val);
}

int minimum(bstnode* root)
{
    if(root==NULL)
    return -1;

    while(root->left!=NULL)
    {
        root=root->left;
    }
    return root->data;
}

int maximum(bstnode* root)
{
    if(root==NULL)
    return -1;

    while(root->right!=NULL)
    {
        root=root->right;
    }
    return root->data;
}

int rangesum(bstnode* root,int l,int r)
{
    if(root==NULL)
    return 0;

    int sum=0;

    if(root->data<=r && root->data>=l)
    sum+=root->data;

    if(root->data<l)
    sum+=rangesum(root->right,l,r);
    else if(root->data>r)
    sum+=rangesum(root->left,l,r);
    else
    sum+=rangesum(root->right,l,r)+rangesum(root->left,l,r);

    return sum;
}

int main()
{
    bstnode* root=input_level();
    if(search(root,5))
    cout<<"Found"<<endl;
    else
    cout<<"Not Found"<<endl;

    cout<<"Min value : "<<minimum(root)<<endl;
    cout<<"Max value : "<<maximum(root)<<endl;

    cout<<"Range sum [7,15] : "<<rangesum(root,7,15)<<endl;
}