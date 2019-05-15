#include<iostream>
#include<string>
using namespace std;
int main()
{
    int m;
    string s;
    while(getline(cin,s))
    {
        cin>>m;
        int left=0;
        int right=s.size()-1;
        while(left<right)
        {
            char b=s[right];
            s[right]=s[left];
            s[left]=b;
            left++;
            right--;
        }
        left=0;right=s.size()-1;
        while(left<m)
        {
            char b=s[left];
            s[left]=s[m-1];
            s[m-1]=b;
            left++;
            m--;
        }
        m=left+1;
        while(m<right)
        {
            char b=s[m];
            s[m]=s[right];
            s[right]=b;
            right--;
            m++;
        }
        for(int i=0;i<s.size();i++)
            cout<<s[i];
            cout<<endl;
    }
    return 0;
}
