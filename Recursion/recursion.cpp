#include<iostream>
#include<math.h>
using namespace std;

int factorial(int n)
{
    if(n==0)
    return 1;
    return n*factorial(n-1);
}

int fibonacci(int n)
{
    if(n==0)
    return 0;
    if(n==1)
    return 1;
    return fibonacci(n-1)+fibonacci(n-2);
}

int power(int x,int n)
{
    if(n==0)
    return 1;
    return x*power(x,n-1);
}

void print_inc(int n)
{
    if(n==0)
    return;
    print_inc(n-1);
    cout<<n<<" ";
}

void print_dec(int n)
{
    if(n==0)
    return;
    cout<<n<<" ";
    print_dec(n-1);
}

int digits(int n)
{
    if(n==0)
    return 0;
    return digits(n/10)+1;
}

int digits_sum(int n)
{
    if(n==0)
    return 0;
    return digits_sum(n/10)+n%10;
}

int multiply(int m, int n)
{
    if(n==0)
    return 0;
    return multiply(m,n-1)+m;
}

int zero(int n)
{
    if(n==0)
    return 0;
    int m=n%10;
    if(m==0)
    return zero(n/10)+1;
    else
    return zero(n/10);
}

float gsum(int n)
{
    if(n==0)
    return 1;
    return gsum(n-1)+1/pow(2,n);
}

bool is_sorted(int arr[], int n)
{
    if(n==0 || n==1)
    return true;
    if(arr[0]>arr[1])
    return false;
    return is_sorted(arr+1,n-1);
}

int array_sum(int arr[], int n)
{
    if(n==0)
    return 0;
    return array_sum(arr+1,n-1)+arr[0];
}

bool find(int arr[],int x, int n)
{
    if(n==0)
    return false;
    if(arr[0]==x)
    return true;
    return find(arr+1,x,n-1);
}

int first_index(int arr[],int n,int x,int i)
{
    if(i==n)
    return -1;
    if(arr[i]==x)
    return i;
    return first_index(arr,n,x,i+1);
}

int last_index(int arr[],int n,int x)
{
    if(n==0)
    return -1;
    if(arr[n-1]==x)
    return n-1;
    return last_index(arr,n-1,x);
}

void all_index(int arr[],int n,int x,int i)
{
    if(i==n)
    return;
    if(arr[i]==x)
    cout<<i<<" ";
    return all_index(arr,n,x,i+1);
}

int count(int arr[],int n,int x,int i)
{
    if(i==n)
    return 0;
    if(arr[i]==x)
    return count(arr,n,x,i+1)+1;
    return count(arr,n,x,i+1);
}

bool palindrome(int arr[],int n,int i,int j)
{
    if(i>=j)
    return true;
    if(arr[i]!=arr[j])
    return false;
    return palindrome(arr,n,i+1,j-1);
}

void print(char arr[])
{
    if(arr[0]=='\0')
    return;
    cout<<arr[0];
    print(arr+1);
}

void print_rev(char arr[])
{
    if(arr[0]=='\0')
    return;
    print_rev(arr+1);
    cout<<arr[0];
}

int length(char arr[])
{
    if(arr[0]=='\0')
    return 0;
    return length(arr+1)+1;
}

void replace(char arr[],char x,char y)
{
    if(arr[0]=='\0')
    return;
    if(arr[0]==x)
    arr[0]=y;
    replace(arr+1,x,y);
}

void remove(char arr[],char x)
{
    if(arr[0]=='\0')
    return;
    if(arr[0]!=x)
    remove(arr+1,x);
    else
    {
        for(int i=0;arr[i]!='\0';i++)
        arr[i]=arr[i+1];
        remove(arr,x);
    }
}

int main()
{
    // int n;
    // cin>>n;
    // cout<<factorial(n);

    // int n;
    // cin>>n;
    // cout<<fibonacci(n);

    // int x,n;
    // cin>>x>>n;
    // cout<<power(x,n);

    // int n;
    // cin>>n;
    // print_inc(n);

    // int n;
    // cin>>n;
    // print_dec(n);

    // int n;
    // cin>>n;
    // cout<<digits(n);

    // int n;
    // cin>>n;
    // cout<<digits_sum(n);

    // int m,n;
    // cin>>m>>n;
    // cout<<multiply(m,n);

    // int n;
    // cin>>n;
    // cout<<zero(n);

    // int n;
    // cin>>n;
    // cout<<gsum(n);

    // int n;
    // cin>>n;
    // int arr[n];
    // for(int i=0;i<n;i++)
    // cin>>arr[i];
    // cout<<is_sorted(arr,n);

    // int n;
    // cin>>n;
    // int arr[n];
    // for(int i=0;i<n;i++)
    // cin>>arr[i];
    // cout<<array_sum(arr,n);

    // int n;
    // cin>>n;
    // int arr[n];
    // for(int i=0;i<n;i++)
    // cin>>arr[i];
    // cout<<find(arr,3,n);

    // int n;
    // cin>>n;
    // int arr[n];
    // for(int i=0;i<n;i++)
    // cin>>arr[i];
    // cout<<first_index(arr,n,6,0);

    // int n;
    // cin>>n;
    // int arr[n];
    // for(int i=0;i<n;i++)
    // cin>>arr[i];
    // cout<<last_index(arr,n,10);
    
    // int n;
    // cin>>n;
    // int arr[n];
    // for(int i=0;i<n;i++)
    // cin>>arr[i];
    // all_index(arr,n,6,0);

    // int n;
    // cin>>n;
    // int arr[n];
    // for(int i=0;i<n;i++)
    // cin>>arr[i];
    // cout<<count(arr,n,1,0);

    // int n;
    // cin>>n;
    // int arr[n];
    // for(int i=0;i<n;i++)
    // cin>>arr[i];
    // cout<<palindrome(arr,n,0,n-1);

    // char arr[]="abcxyz";
    // print(arr);
    // cout<<endl;
    // print_rev(arr);
    // cout<<endl<<length(arr);

    // char arr[]="abcdab";
    // print(arr);
    // replace(arr,'a','x');
    // cout<<endl;
    // print(arr);

    char arr[]="aaabcdabef";
    print(arr);
    remove(arr,'a');
    cout<<endl;
    print(arr);
}