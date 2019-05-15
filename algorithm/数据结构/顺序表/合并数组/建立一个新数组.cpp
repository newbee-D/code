
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int a[]= {3,2,5,7};
    int b[]= {1,3,7,4,8,6,5};
    int c[11];
    int j=0;
    sort(a,a+4);//ÉýÐò
    sort(b,b+7);
    int i,k;
    for(i=0; i<4; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    for(k=0; k<7; k++)
    {
        cout<<b[k]<<" ";
    }
    cout<<endl;
    int na=4,nb=7;
    i=0;
    k=0;
    while(i<na && k<nb)
    {
        int xa=a[i];
        int xb=b[k];
        if(xa<=xb)
        {
            c[j]=xa;
            i++;
        }
        else
        {
            c[j]=xb;
            k++;
        }
        j++;
    }
    while(i<na)c[j++]=a[i++];
    while(k<nb) c[j++]=b[k++];
    for(i=0; i<j; i++)
    {
        cout<<c[i]<<" ";
    }
    cout<<endl;
    return 0;
}
