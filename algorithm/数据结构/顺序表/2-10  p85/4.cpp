#include<iostream>
using namespace std;
int main()
{
    int date[]= {3,2,5,7,12,19,31};
    int n=sizeof(date)/sizeof(int);
    int s;
    cin>>s;
    if(n==-1)return false;
    if (s<1 || s>n+1)return false;
    for(int j=s; j<n; j++)
        date[j]=date[j+1];
    n--;
    for(int i=0; i<n; i++)
        cout<<date[i]<<" ";
    cout<<endl;
    return 0;

}


