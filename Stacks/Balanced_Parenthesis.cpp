#include<iostream>
#include<stack>
using namespace std;

bool balanced_parenthesis(string a)
{
    stack<char> s;

    for(int i=0;i<a.size();i++)
    {
        if(a[i]=='(' || a[i]=='[' || a[i]=='{')
        s.push(a[i]);
        else
        {
            if(s.empty())
            return false;
            else if(a[i]==')')
            {
                if(s.top()=='(')
                s.pop();
                else
                return false;
            }
            else if(a[i]==']')
            {
                if(s.top()=='[')
                s.pop();
                else
                return false;
            }
            else if(a[i]=='}')
            {
                if(s.top()=='{')
                s.pop();
                else
                return false;
            }
        }
    }
    if(s.empty())
    return true;
    return false;
}

int main()
{
    string s;
    getline(cin,s);
    cout<<balanced_parenthesis(s);
}