#include<iostream>
using namespace std;
double average(int a[],int len)
{
    if(len==1)
        return a[0];
    else
    {
        int b;
        return a[0]+average(a+1,len-1);
    }
}
int main()
{
    int a[]={1,2,3,4,5,6,7};
    average(a,7);
    cout<<average(a,7)/7;
    return 0;
}
