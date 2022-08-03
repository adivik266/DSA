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

class BST
{
    bstnode* root;

    void print(bstnode* root)
    {
        queue<bstnode*> q;
        q.push(root);
        while(!q.empty())
        {
            bstnode* temp=q.front();
            q.pop();

            cout<<temp->data<<" : ";
            if(temp->left)
            {
                q.push(temp->left);
                cout<<"L"<<temp->left->data<<" ";
            }
            if(temp->right)
            {
                q.push(temp->right);
                cout<<"R"<<temp->right->data<<" ";
            }
            cout<<endl;
        }
    }

    bool hasdata(bstnode* root,int val)
    {
        if(root==NULL)
        return false;

        if(root->data==val)
        return true;

        if(root->data>val)
        return hasdata(root->left,val);
        else
        return hasdata(root->right,val);
    }

    bstnode* insert(bstnode* root,int val)
    {
        if(root==NULL)
        {
            bstnode* temp=new bstnode(val);
            return temp;
        }

        if(root->data > val)
        root->left=insert(root->left,val);
        else
        root->right=insert(root->right,val);

        return root;
    }

    bstnode* deletedata(bstnode* root,int val)
    {
        if(root==NULL)
        return NULL;

        if(root->data > val)
        root->left=deletedata(root->left,val);
        else if(root->data < val)
        root->right=deletedata(root->right,val);
        else
        {
            if(root->left==NULL && root->right==NULL)
            {
                delete root;
                return NULL;
            }
            else if(root->right==NULL)
            {
                bstnode* temp=root->left;
                root->left=NULL;
                delete root;
                return temp;
            }
            else if(root->left==NULL)
            {
                bstnode* temp=root->right;
                root->right=NULL;
                delete root;
                return temp;
            }
            else
            {
                bstnode* temp=root->right;
                while(temp->left)
                temp=temp->left;
                
                root->data=temp->data;

                root->right=deletedata(root->right,temp->data);
            }
        }
        return root;
    }

    pair<bstnode*,bstnode*> convert_to_LL(bstnode* root)
    {
        if(root->left==NULL && root->right==NULL)
        {
            pair<bstnode*,bstnode*> p;
            p.first=root;
            p.second=root;
            return p;
        }
        else if(root->right==NULL)
        {
            pair<bstnode*,bstnode*> leftLL=convert_to_LL(root->left);
            leftLL.second->right=root;
            pair<bstnode*,bstnode*> p;
            p.first=leftLL.first;
            p.second=root;
            return p;
        }
        else if(root->left==NULL)
        {
            pair<bstnode*,bstnode*> rightLL=convert_to_LL(root->right);
            root->right=rightLL.first;
            pair<bstnode*,bstnode*> p;
            p.first=root;
            p.second=rightLL.second;
            return p;
        }
        else
        {
            pair<bstnode*,bstnode*> leftLL=convert_to_LL(root->left);
            pair<bstnode*,bstnode*> rightLL=convert_to_LL(root->right);
            leftLL.second->right=root;
            root->right=rightLL.first;
            pair<bstnode*,bstnode*> p;
            p.first=leftLL.first;
            p.second=rightLL.second;
            return p;
        }
    }

    public:

    BST()
    {
        root=NULL;
    }

    ~BST()
    {
        delete root;
    }

    void deletedata(int data)
    {
        root=deletedata(root,data);
    }

    void insert(int data)
    {
        root=insert(root,data);
    }

    bool hasdata(int data)
    {
        return hasdata(root,data);
    }

    void print()
    {
        print(root);
    }

    bstnode* convert_to_LL()
    {
        pair<bstnode*,bstnode*> p = convert_to_LL(root);
        return p.first;
    }
};

int main()
{
    BST b;
    b.insert(10);
    b.insert(5);
    b.insert(20);
    b.insert(7);
    b.insert(3);
    b.insert(15);

    b.print();
    cout<<endl;

    /*int data;
    cin>>data;
    cout<<b.hasdata(data)<<endl;*/

    /*b.deletedata(10);
    b.print();
    cout<<endl;

    b.deletedata(20);
    b.print();
    cout<<endl;

    b.deletedata(3);
    b.print();
    cout<<endl;*/

    bstnode* head = b.convert_to_LL();
    bstnode* temp=head;

    while(temp)
    {
        cout<<temp->data<<"->";
        temp=temp->right;
    }


}