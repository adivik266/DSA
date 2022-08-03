#include<iostream>
#include<vector>
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

btnode* helper(vector<int> inorder, vector<int> preorder,int ins,int ine,int pres,int pree)
{
    if(ins>ine)
    return NULL;

    int rootdata=preorder[pres];
    int rootindex=-1;
    for(int i=ins;i<=ine;i++)
    {
        if(inorder[i]==rootdata)
        rootindex=i;
    }

    int leftins = ins;
    int leftine = rootindex-1;
    int leftpres = pres+1;;
    int leftpree = leftine - leftins + leftpres;

    int rightins = rootindex+1;
    int rightine = ine;
    int rightpres = leftpree+1;
    int rightpree = pree;

    btnode* root = new btnode(rootdata);
    root->left=helper(inorder,preorder,leftins,leftine,leftpres,leftpree);
    root->right=helper(inorder,preorder,rightins,rightine,rightpres,rightpree);

    return root;
}

btnode* build(vector<int> inorder, vector<int> preorder)
{
    int n=inorder.size();
    return helper(inorder,preorder,0,n-1,0,n-1);
}

void print_level(btnode* root)
{
    queue<btnode*> q;
    q.push(root);
    while(!q.empty())
    {
        btnode* temp=q.front();
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

int main()
{
    int n;
    cin>>n;

    vector<int> inorder,preorder;
    int inp;

    for(int i=0;i<n;i++)
    {
        cin>>inp;
        inorder.push_back(inp);
    }

    for(int i=0;i<n;i++)
    {
        cin>>inp;
        preorder.push_back(inp);
    }

    btnode* root=build(inorder,preorder);

    print_level(root);
}