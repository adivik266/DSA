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

btnode* helper(vector<int> inorder, vector<int> postorder,int ins,int ine,int posts,int poste)
{
    if(ins>ine)
    return NULL;

    int rootdata=postorder[poste];
    int rootindex=-1;
    for(int i=ins;i<=ine;i++)
    {
        if(inorder[i]==rootdata)
        rootindex=i;
    }

    int leftins = ins;
    int leftine = rootindex-1;
    int leftposts = posts;
    int leftposte = leftine - leftins + leftposts;

    int rightins = rootindex+1;
    int rightine = ine;
    int rightposts = leftposte+1;
    int rightposte = poste-1;

    btnode* root = new btnode(rootdata);
    root->left=helper(inorder,postorder,leftins,leftine,leftposts,leftposte);
    root->right=helper(inorder,postorder,rightins,rightine,rightposts,rightposte);

    return root;
}

btnode* build(vector<int> inorder, vector<int> postorder)
{
    int n=inorder.size();
    return helper(inorder,postorder,0,n-1,0,n-1);
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

    vector<int> inorder,postorder;
    int inp;

    for(int i=0;i<n;i++)
    {
        cin>>inp;
        inorder.push_back(inp);
    }

    for(int i=0;i<n;i++)
    {
        cin>>inp;
        postorder.push_back(inp);
    }

    btnode* root=build(inorder,postorder);

    print_level(root);
}