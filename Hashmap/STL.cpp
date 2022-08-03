#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

int main()
{
    unordered_map<string,int> mymap;

    //insert

    pair<string,int> p("abc",1);
    mymap.insert(p);

    mymap["def"]=2;

    //access

    cout<<mymap["abc"]<<endl;
    cout<<mymap.at("def")<<endl;

    cout<<mymap["ghi"]<<endl;

    //size

    cout<<"Size : "<<mymap.size()<<endl;

    //check presence

    if(mymap.count("ghi")==0)
    cout<<"Not present"<<endl;
    else
    cout<<"Present"<<endl;

    //update

    mymap["abc"]=20;

    //delete

    mymap.erase("ghi");

    cout<<"Size : "<<mymap.size()<<endl;

    if(mymap.count("ghi")==0)
    cout<<"Not present"<<endl;
    else
    cout<<"Present"<<endl;
}