#include<iostream>
#include<stack>
using namespace std;

int postfix(string s)
{
    stack<int> st;

    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='0' && s[i]<='9')
        st.push(s[i]-'0');

        else
        {
            int b=st.top();
            st.pop();
            int a=st.top();
            st.pop();

            switch(s[i])
            {
                case '+':
                   st.push(a+b);
                   break;

                case '-':
                   st.push(a-b);
                   break;

                case '*':
                   st.push(a*b);
                   break;

                case '/':
                   st.push(a/b);
                   break;

                default:
                   break;
            }
        }
    }

    return st.top();
}

int main()
{
    cout<<postfix("46+2/5*7+");
}