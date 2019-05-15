
#include<iostream>
#include<string>
using namespace std;
int fun1(int a[],int m)
{int b=a[0],i,c=0;
 for(i=0; i<m;)
    {
        if(m<0)  cout<<"³ö´íÐÅÏ¢"<<endl;
        if(a[i]<=b)
      {
          b=a[i];
          c=i;
          i++;
      }
      else i++;
    }
     cout<<b<<endl;
     a[c]=a[m-1];
     //delete a[m];
}
int main()
{
    int n;
    cin>>n;
    int a[n];//={1,4,5,3,6,7,8,0},n;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    fun1(a,n);
    for(int m=0;m<n-1;m++) cout<<a[m]<<" ";
        cout<<endl;
   return 0;
}
