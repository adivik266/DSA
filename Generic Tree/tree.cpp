#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class treenode
{
    public:
    int data;
    vector<treenode*> children;

    treenode(int val)
    {
        data=val;
    }

    ~treenode()
    {
        for(int i=0;i<children.size();i++)
        delete children[i];
    }
};

void print(treenode* root)
{
    if(root==NULL)
    return;

    cout<<root->data<<": ";
    for(int i=0;i<root->children.size();i++)
    cout<<root->children[i]->data<<",";
    cout<<endl;

    for(int i=0;i<root->children.size();i++)
    print(root->children[i]);
}

void print_level(treenode* root)
{
    queue<treenode*> q;
    q.push(root);

    while(!q.empty())
    {
        treenode* temp=q.front();
        q.pop();

        cout<<temp->data<<": ";
        for(int i=0;i<temp->children.size();i++)
        cout<<temp->children[i]->data<<",";
        cout<<endl;

        for(int i=0;i<temp->children.size();i++)
        q.push(temp->children[i]);
    }
}

treenode* input_rec()
{
    int val;
    cin>>val;
    treenode* root=new treenode(val);
    int n;
    cout<<"No. of children: ";
    cin>>n;

    while(n--)
    {
        treenode* temp=input_rec();
        root->children.push_back(temp);
    }
    return root;
}

void input_level(treenode* &root,int val)
{
    treenode* temp = new treenode(val);
    root=temp;
    queue<treenode*> q;
    q.push(root);

    while(!q.empty())
    {
        treenode* temp1=q.front();
        q.pop();

        cout<<"No. of children of "<<temp1->data<<" : ";
        int n;
        cin>>n;

        for(int i=0;i<n;i++)
        {
            int c;
            cin>>c;

            treenode* child=new treenode(c);
            q.push(child);
            temp1->children.push_back(child);
        }
    }
}

int count_nodes(treenode* root)
{
    if(root==NULL)
    return 0;

    int count=1;
    for(int i=0;i<root->children.size();i++)
    count+=count_nodes(root->children[i]);
    return count;
}

int height(treenode* root)
{
    int final=0;
    for(int i=0;i<root->children.size();i++)
    final=max(final,height(root->children[i]));
    
    return final+1;
}

void print_at_level_k(treenode* root,int k)
{
    if(root==NULL)
    return;
    if(k==0)
    {
        cout<<root->data<<endl;
        return;
    }

    for(int i=0;i<root->children.size();i++)
    print_at_level_k(root->children[i],k-1);
}

int count_leaf_nodes(treenode* root)
{
    if(root->children.size()==0)
    return 1;
    int ans=0;
    for(int i=0;i<root->children.size();i++)
    ans+=count_leaf_nodes(root->children[i]);
    return ans;
}

void preorder(treenode* root)
{
    if(root==NULL)
    return;
    cout<<root->data<<" ";
    for(int i=0;i<root->children.size();i++)
    preorder(root->children[i]);
}

void postorder(treenode* root)
{
    if(root==NULL)
    return;
    for(int i=0;i<root->children.size();i++)
    postorder(root->children[i]);
    cout<<root->data<<" ";
}

void delete_tree(treenode* root)
{
    if(root==NULL)
    return;
    for(int i=0;i<root->children.size();i++)
    delete_tree(root->children[i]);
    delete root;
}

int main()
{
    /*treenode* root = new treenode(1);
    treenode* n1 = new treenode(2);
    treenode* n2 = new treenode(3);

    root->children.push_back(n1);
    root->children.push_back(n2);*/

    /*treenode* root=input_rec();

    print(root);*/

    // 3 2 3 4 2 5 6 1 7 1 8 0 0 0 0

    treenode* root=NULL;
    input_level(root,1);
    print(root);
    print_level(root);
    cout<<"No. of nodes : "<<count_nodes(root)<<endl;
    cout<<"Height of tree : "<<height(root)<<endl;
    cout<<"Nodes at level 1 : "<<endl;
    print_at_level_k(root,1);
    cout<<"No. of leaf nodes : "<<count_leaf_nodes(root)<<endl;
    cout<<"Preorder traversal : ";
    preorder(root);
    cout<<endl;
    cout<<"Postorder traversal : ";
    postorder(root);
    //delete_tree(root);
    delete root;
}