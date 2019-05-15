#include<iostream>
#include<algorithm>
#include<fstream>
#include<stdio.h>
using namespace std;
const int Max=100001;
int a[Max];

void sellect_sort(int a[],int n)
{
    int i,j;
    int p;
    for(i=0; i<n-1; i++)
    {
        p=i;
        for(j=i+1; j<n; j++)
        {
            if(a[p]>a[j])p=j;
        }
        if(p!=j)
        {
            swap(a[p],a[i]);
        }
    }
}
int main()
{
    /*ofstream cout("out.txt ");      //把结果写在文件里
    ifstream cin("test1.in");
    freopen("test1.txt","r",stdin);//c语言
    freopen("out2.txt","w",stdout);*/

    int a[]= {2,5,3,7,4};
    int n=sizeof(a)/sizeof(int);
    cin>>n;
    sellect_sort(a,n);

    for(int j=0; j<n; j++)
        cin>>a[j];
    for(int i=0; i<n; i++)
    {
        cout<<a[i];
        if(i<n-1)
            cout<<" ";
    }
    return 0;
}
