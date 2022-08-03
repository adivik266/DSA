#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;

string dup_adj(string s)
{
    stack<char> st;
    for(int i=0;i<s.size();i++)
    {
        if(st.empty() || s[i]!=st.top())
        st.push(s[i]);
        else
        st.pop();
    }

    string ans;
    while(!st.empty())
    {
        ans+=st.top();
        st.pop();
    }

    reverse(ans.begin(),ans.end());
    return ans;
}

int main()
{
    string s;
    getline(cin,s);
    cout<<dup_adj(s);
}