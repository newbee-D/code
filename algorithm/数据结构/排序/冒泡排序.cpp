#include<iostream>
#include<algorithm>
using namespace std;

void bubble_sort(int a[],int n)
{
    int i,j;
    for(i=0;i<n-1; i++)
    {
        for(j=0; j<n-1-i; j++)
        {
            if(a[j]>a[j+1])
                swap(a[j],a[j+1]);
        }
    }
}
int main()
{
    int a[]= {2,5,3,7,4};
    int n=sizeof(a)/sizeof(int);
    bubble_sort(a,n);
    for(int i=0; i<n; i++)
    {
        cout<<a[i];
        if(i<n-1)
            cout<<" ";
    }
    return 0;
}
