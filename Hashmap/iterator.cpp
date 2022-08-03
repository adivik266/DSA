#include<iostream>
#include<unordered_map>
#include<map>
using namespace std;

int main()
{
    unordered_map<string,int> m;
    m["abc"]=1;
    m["def"]=2;
    m["ghi"]=3;
    m["jkl"]=4;
    m["mno"]=5;

    for(unordered_map<string,int>::iterator it=m.begin();it!=m.end();it++)
    cout<<"Key : "<<it->first<<" Value : "<<it->second<<endl;

    cout<<endl;

    map<string,int> m2;
    m2["def"]=2;
    m2["abc"]=10;
    m2["mno"]=15;
    m2["ghi"]=339;
    m2["jkl"]=4;
    

    for(auto it=m2.begin();it!=m2.end();it++)
    cout<<"Key : "<<it->first<<" Value : "<<it->second<<endl;
}