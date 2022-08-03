#include<iostream>
using namespace std;

int steps(int n)
{
    if(n==0)
    return 0;
    return steps(n-1)+1+steps(n-1);
}

void toh(int n,char s,char d,char h)
{
    if(n==0)
    return;
    toh(n-1,s,h,d);
    cout<<"Moving disk "<<n<<" from "<<s<<" to "<<d<<endl;
    toh(n-1,h,d,s);
}

int main()
{
    int n;
    cin>>n;
    cout<<"No. of steps: "<<steps(n)<<endl;
    toh(n,'A','C','B');
}