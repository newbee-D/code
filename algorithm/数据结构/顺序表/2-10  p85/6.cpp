#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int date[]= {3,2,5,7,12,19,31};
    int n=sizeof(date)/sizeof(int);
    sort(date,date+7);
    for(int i=0; i<n; i++)
        cout<<date[i]<<" ";
    cout<<endl;
    int s,m;
    cin>>s>>m;
    if(n==-1)return false;
    if (s<1 || m<1 || s>n+1 || m>n+1)return false;
    for(int j=s+1; j<n; j++)
    {
        date[j]=date[m++];
        n--;
    }
    n++;
    for(int i=0; i<n; i++)
        cout<<date[i]<<" ";
    cout<<endl;
    return 0;

}
