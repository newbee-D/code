#include<iostream>
#include<string.h>
using namespace std;
void reverse1(string a)
{
    int left=0;
    int right=a.size()-1;
    while(left<right)
    {
        char b=a[right];
        a[right]=a[left];
        a[left]=b;
        left++;
        right--;
    }
    for(int i=0;i<a.size();i++)
        cout<<a[i];
    cout<<endl;
    left=0;
    right=0;
    int sum=0;
    while(right<a.size()){
       for(int i=sum;i<a.size();i++)
       {
           if(a[i]!=' '){sum=right+1;right++;}
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
       left=sum+1;
       right=sum+1;
       sum=sum+1;
    }
    for(int i=0;i<a.size();i++)
        cout<<a[i];
}
int main()
{
    string s;
    getline(cin,s);
    reverse1(s);
    return 0;
}
