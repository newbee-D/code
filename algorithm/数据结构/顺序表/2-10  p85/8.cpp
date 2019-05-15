#include<iostream>
using namespace std;
int main(int argc,char *argy[])
{
    int a[]= {1,1,2,2,3,3,4,4,5,5,6};
    int n=sizeof(a)/sizeof(int);
    int index=0;
    for(int i=1; i<=n; i++)
    {
        if(a[index]==a[i])continue;
        else
        {
            index++;
            a[index]=a[i];
        }

    }
    for(int i=0; i<index; i++)
        cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}
