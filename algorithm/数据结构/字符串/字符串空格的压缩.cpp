#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s="abc   def   hig";
    int sum1=0,sum2=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]==' ' && s[i+1]==' ')sum1++;
        else sum2++;
    }
    int n=sum2;
    string a;
    int j=0;
    for(int i=0;i<n;)
    {
        if(s[j]==' ' && s[j+1]==' ')j++;
        else if(s[j]==' ' && s[j+1]!=' '){a[i]=s[j];j++;i++;}
        else {a[i]=s[j];i++;j++;}
    }
    for(int i=0;i<n;i++)
        cout<<a[i];
    cout<<endl;
    int left=0;
    int right=0;
    int sum3=0;
    while(right<n)
    {
        for(int i=sum3;i<n;i++)
        {
            if(a[i]!=' '){right++;sum3=right+1;}
            else break;
        }
        right=right-1;
        while(left<right)
        {
            char b=a[right];
            a[right]=a[left];
            a[left]=b;
            left++;
            right--;
        }
        left=sum3;
        right=sum3+1;
        sum3=sum3+1;
    }
    for(int i=0;i<n;i++)
        cout<<a[i];
    cout<<endl;
    return 0;
}
