#include<iostream>
using namespace std;

template<typename T,typename V>

class group
{
    T x;
    V y;
    public:

    void setx(T n)
    {
        x=n;
    }

    T getx()
    {
        return x;
    }

    void sety(V n)
    {
        y=n;
    }

    V gety()
    {
        return y;
    }
};

int main()
{
    group<int,double> p;
    p.setx(4);
    p.sety(7.913);
    cout<<p.getx()<<" "<<p.gety()<<endl;

    group<group<int,double>,char> p1;

    group<int,double> temp;
    temp.setx(19);
    temp.sety(2.939);

    p1.setx(temp);
    p1.sety('d');
    cout<<p1.getx().getx()<<" "<<p1.getx().gety()<<" "<<p1.gety()<<endl;
}

