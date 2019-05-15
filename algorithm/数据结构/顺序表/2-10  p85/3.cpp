#include<iostream>
using namespace std;
int date[]= {3,2,5,7,12};
int n=sizeof(date)/sizeof(int);
bool Insert(int i,int &x)
{
    if(n==-1)return false;
    if (i<1 || i>n+1)return false;
    for (int j=n; j>=i; j--)
        date[j+1]=date[j];
    date[i]=x;
    for(int j=0; j<6; j++)
        cout<<date[j]<<" ";
    cout<<endl;
    return true;
}
int main()
{
    int i,x;
    cin>>i>>x;
    Insert(i,x);
    return 0;
}
