#include<iostream>
using namespace std;

template<typename V>

class mapnode
{
    public:
    string key;
    V value;
    mapnode* next;

    mapnode(string key, V value)
    {
        this->key=key;
        this->value=value;
        next=NULL;
    }

    ~mapnode()
    {
        delete next;
    }
};

template<typename V>

class mymap
{
    mapnode<V>** bucket;
    int count;
    int bucketsize;

    int hashfunction(string key)
    {
        int hashcode=0;

        int base=1, p=37;
        for(int i=key.size()-1;i>=0;i--)
        {
            hashcode += key[i]*base;
            base*=p;

            hashcode%=bucketsize;     ///(a*b*c)%n = (a%n + b%n + c%n)%n
            base%=bucketsize;
        }

        return hashcode%bucketsize;
    }

    void rehash()
    {
        mapnode<V>** temp=bucket;
        bucket = new mapnode<V>*[2*bucketsize];
        for(int i=0;i<2*bucketsize;i++)
        bucket[i]=NULL;

        int oldbucketsize=bucketsize;
        bucketsize*=2;
        count=0;

        for(int i=0;i<oldbucketsize;i++)
        {
            mapnode<V>* head = temp[i];
            while(head!=NULL)
            {
                string key = head->key;
                V value = head->value;
                insert(key,value);
                head=head->next;
            }
        }

        for(int i=0;i<oldbucketsize;i++)
        delete temp[i];

        delete []temp;
    }

    public:
    
    mymap()
    {
        count=0;
        bucketsize=5;
        bucket = new mapnode<V>*[bucketsize];
        for(int i=0;i<bucketsize;i++)
        bucket[i]=NULL;
    }

    ~mymap()
    {
        for(int i=0;i<bucketsize;i++)
        delete bucket[i];
        delete []bucket;
    }

    int size()
    {
        return count;
    }

    void insert(string key, V value)
    {
        int index = hashfunction(key);
        mapnode<V>* head = bucket[index];

        while(head!=NULL)
        {
            if(head->key == key)
            {
                head->value = value;
                return;
            }
            head=head->next;
        }

        mapnode<V>* temp = new mapnode<V>(key,value);
        temp->next = bucket[index];
        bucket[index] = temp;

        count++;

        double load = 1.0*count/bucketsize;
        if(load>0.7)
        rehash();
    }

    void remove(string key)
    {
        int index = hashfunction(key);
        mapnode<V>* prev = NULL;
        mapnode<V>* curr = bucket[index];

        while(curr!=NULL)
        {
            if(curr->key==key)
            {
                if(prev==NULL)
                bucket[index] = curr->next;
                else
                prev->next=curr->next;

                curr->next=NULL;
                delete curr;
                count--;
                return;
            }
            prev=curr;
            curr=curr->next;
        }
    }

    V getvalue(string key)
    {
        int index = hashfunction(key);
        mapnode<V>* head = bucket[index];

        while(head!=NULL)
        {
            if(head->key==key)
            return head->value;

            head=head->next;
        }

        return 0;  
    }
};

int main()
{
    mymap<int> m;
    for(int i=0;i<10;i++)
    {
        char c = '0'+i;
        string key = "abc";
        key+=c;
        int val = i+1;
        m.insert(key,val);
    }
    cout<<m.size()<<endl;

    m.remove("abc2");
    m.remove("abc7");

    for(int i=0;i<10;i++)
    {
        char c = '0'+i;
        string key = "abc";
        key+=c;
        cout<<key<<" "<<m.getvalue(key)<<endl;
    }
    cout<<m.size()<<endl;
}