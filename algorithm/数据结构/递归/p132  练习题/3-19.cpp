#include<iostream>
using namespace std;
int f(int n)
{
    return n==0 || n==1 ? n : n*f(n-1);
}
int main()
{
    int n;
    while(cin>>n)
    {
        cout<<f(n)<<endl;
    }
    return 0;
}
