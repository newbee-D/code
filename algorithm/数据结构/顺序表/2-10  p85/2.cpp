#include<iostream>
#include<stdlib.h>
using namespace std;
int date[]= {3,2,5,7,12};
int n=sizeof(date)/sizeof(int);
bool Remove(int i,int &x)
{
    if(n==-1)return false;
    if (i<1 || i>n+1)return false;
    x=date[i-1];
    for(int j=i; j<=n; j++)
        date[j-1]=date[j];
    n--;
    return true;
}
int main()
{
    int i,x;
    cin>>i;
    Remove(i,x);
    for(int j=0; j<n; j++)
        cout<<date[j]<<" ";
    cout<<endl;
    return 0;

}
