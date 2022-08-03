#include<iostream>
#include<queue>
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

pair<int,int> height_diameter(btnode* root)
{
    if(root==NULL)
    {
        pair<int,int> p;
        p.first=0;
        p.second=0;
        return p;
    }

    pair<int,int> leftans = height_diameter(root->left);
    pair<int,int> rightans = height_diameter(root->right);

    pair<int,int> p;
    p.first = max(leftans.first,rightans.first)+1;
    p.second = max(leftans.first+rightans.first,max(leftans.second,rightans.second));
    return p;
}

int main()
{
    btnode* root=NULL;
    input_level(root,1);
    pair<int,int> p=height_diameter(root);

    cout<<"Height : "<<p.first<<"\n"<<"Diameter : "<<p.second;
}