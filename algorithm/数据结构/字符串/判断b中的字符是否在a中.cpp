#include<iostream>
#include<string>
using namespace std;
int main()
{
    //int n,m;
    string s1,s2;
    while(getline(cin,s1)&&getline(cin,s2))
    {
        /*char a[n],b[m];
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<m;i++)
            cin>>b[i];*/
        int first=0;
        int last=0;
        while(first<s1.size() && last<s2.size())
        {
            if(s1[first]==s2[last])
            {
                first=0;
                last++;
            }
            else first++;
        }
        if(last<s2.size())cout<<"s1中不包含s2的所有字符"<<endl;
        else cout<<"s1中包含s2的所有字符"<<endl;
    }
    return 0;
}
