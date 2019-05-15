#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s="abc   def   ghi";
    int sum1=0,sum2=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]==' ')sum1++;
        else sum2++;
    }
    int n=sum1*3+sum2;
    int j=0;
    string a;
    for(int i=n-1;i>=0;)
    {
        if(s[j]!=' '){a[i]=s[j];i--;j++;}
        else {a[i]='2';a[i-1]='0';a[i-2]='%';i-=3;j++;}
    }
    for(int i=n-1;i>=0;i--)
        cout<<a[i];
    cout<<endl;
    return 0;
}
