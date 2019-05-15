#include<iostream>
using namespace std;
int Max(int a,int b)
{
    return a>b ? a: b;
}
int getMax(int a[],int len)
{
    if(len==1)
        return a[0];
    else
    {
        return Max(a[0],getMax(a+1,len-1));
    }

}
int main()
{
    int a[]= {1,2,3,4,5,6,7};
    getMax(a,7);
    cout<<getMax(a,7);
}
