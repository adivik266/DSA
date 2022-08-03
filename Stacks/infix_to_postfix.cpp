#include<iostream>
#include<stack>
using namespace std;

int precedence(char a)
{
    if(a=='^')
    return 3;
    if(a=='*' || a=='/')
    return 2;
    if(a=='+' || a=='-')
    return 1;
    return -1;
}

string postfix(string s)
{
    stack<char> st;
    string res;

    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='0' && s[i]<='9')
        res+=s[i];

        else if(s[i]=='(')
        st.push(s[i]);

        else if(s[i]==')')
        {
            while(!st.empty() && st.top()!='(')
            {
                res+=st.top();
                st.pop();
            }
            if(!st.empty())
            st.pop();
        }

        else
        {
            while(!st.empty() && precedence(st.top())>=precedence(s[i]))
            {
                res+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }

    while(!st.empty())
    {
        res+=st.top();
        st.pop();
    }

    return res;
}

int main()
{
    string s;
    getline(cin,s);
    cout<<postfix(s);
}