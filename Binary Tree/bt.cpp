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

    ~btnode()
    {
        delete left;
        delete right;
    }
};

void print(btnode* root)
{
    if(root==NULL)
    return;

    cout<<root->data<<": ";
    if(root->left)
    cout<<"L"<<root->left->data<<" ";
    if(root->right)
    cout<<"R"<<root->right->data;
    cout<<endl;

    print(root->left);
    print(root->right);
}

void print_level(btnode* root)
{
    queue<btnode*> q;
    q.push(root);
    while(!q.empty())
    {
        int n=q.size();

        while(n)
        {
            btnode* temp=q.front();
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

btnode* input_rec()
{
    int val;
    cin>>val;

    if(val==-1)
    return NULL;

    btnode* root=new btnode(val);
    root->left=input_rec();
    root->right=input_rec();

    return root;
}

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

int count_nodes(btnode* root)
{
    if(root==NULL)
    return 0;
    return count_nodes(root->left)+count_nodes(root->right)+1;
}

void inorder(btnode* root)
{
    if(root==NULL)
    return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(btnode* root)
{
    if(root==NULL)
    return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(btnode* root)
{
    if(root==NULL)
    return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

int height(btnode* root)
{
    if(root==NULL)
    return 0;
    return max(height(root->left),height(root->right))+1;
}

bool helper(btnode* lefttree, btnode* righttree)
{
    if(lefttree==NULL && righttree==NULL)
    return true;

    if(lefttree && righttree && lefttree->data==righttree->data)
    return (helper(lefttree->left,righttree->right) && helper(lefttree->right,righttree->left));
}

bool issymmetric(btnode* root)
{
    if(root==NULL)
    return true;

    return helper(root->left,root->right);
}

bool search(btnode* root,int key)
{
    if(root==NULL)
    return false;
    if(root->data==key)
    return true;

    return (search(root->left,key)||search(root->right,key));
}

int minvalue(btnode* root,int &ans)
{
    if(root==NULL)
    return INT_MAX;
    ans=min(ans,root->data);
    minvalue(root->left,ans);
    minvalue(root->right,ans);

    return ans;
}

int maxvalue(btnode* root,int &ans)
{
    if(root==NULL)
    return INT_MAX;
    ans=max(ans,root->data);
    maxvalue(root->left,ans);
    maxvalue(root->right,ans);

    return ans;
}

int count_leaf_nodes(btnode* root)
{
    if(root==NULL)
    return 0;
    if(root->left==NULL && root->right==NULL)
    return 1;

    return count_leaf_nodes(root->left)+count_leaf_nodes(root->right);
}

int diameter(btnode* root)
{
    if(root==NULL)
    return 0;

    return max(height(root->left)+height(root->right),max(diameter(root->left),diameter(root->right)));
}

int main()
{
    /*btnode* root=new btnode(1);
    btnode* n1=new btnode(2);
    btnode* n2=new btnode(3);

    root->left=n1;
    root->right=n2;*/

    /*btnode* root=input_rec();
    
    print(root);*/

    // 2 30 4 5 6 7 -1 -1 -1 -1 8 -7 -1 -1 -1 -1 -1 -1

    btnode* root=NULL;
    input_level(root,1);

    print_level(root);
    
    cout<<"No. of nodes : "<<count_nodes(root)<<endl;

    cout<<"Inorder traversal : ";
    inorder(root);
    cout<<endl;
    cout<<"Preorder traversal : ";
    preorder(root);
    cout<<endl;
    cout<<"Postorder traversal : ";
    postorder(root);
    cout<<endl;

    cout<<"Height : "<<height(root)<<endl;

    if(issymmetric(root))
    cout<<"Symmetric"<<endl;
    else
    cout<<"Not Symmetric"<<endl;

    cout<<"Searching for 8 : ";
    if(search(root,8))
    cout<<"Found"<<endl;
    else
    cout<<"Not Found"<<endl;

    cout<<"Min value : "<<minvalue(root,root->data)<<endl;
    cout<<"Max value : "<<maxvalue(root,root->data)<<endl;

    cout<<"No. of leaf nodes : "<<count_leaf_nodes(root)<<endl;

    cout<<"Diameter : "<<diameter(root)<<endl;


    delete root;
}