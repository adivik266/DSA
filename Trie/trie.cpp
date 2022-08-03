#include<bits/stdc++.h>
using namespace std;

class TrieNode
{
    public:
    bool terminal;
    TrieNode* child[26];

    TrieNode()
    {
        terminal=false;
        for(int i=0;i<26;i++)
        child[i]=NULL;
    }
};

void insert(string word,TrieNode* trie)
{
    int n=word.size();
    for(int i=0;i<n;i++)
    {
        if(trie->child[word[i]-'A']==NULL)
        trie->child[word[i]-'A'] = new TrieNode();

        trie = trie->child[word[i]-'A'];
    }
    trie->terminal=true;
}

bool search(string word,TrieNode* trie)
{
    int n=word.size();
    for(int i=0;i<n;i++)
    {
        if(trie->child[word[i]-'A'])
        trie=trie->child[word[i]-'A'];
        else
        return false;
    }
    return trie->terminal;
}

int main()
{
    vector<string> dict;
    dict.push_back("ARE");
    dict.push_back("AS");
    dict.push_back("DO");
    dict.push_back("DOT");
    dict.push_back("NEW");
    dict.push_back("NEWS");
    dict.push_back("NO");
    dict.push_back("NOT");

    TrieNode* root=new TrieNode();
    for(int i=0;i<dict.size();i++)
    insert(dict[i],root);

    cout<<search("ARE",root)<<endl;
    cout<<search("AR",root)<<endl;
    cout<<search("DONE",root)<<endl;
    cout<<search("NEW",root)<<endl;
    cout<<search("NEWS",root)<<endl;
    cout<<search("WIN",root)<<endl;
}