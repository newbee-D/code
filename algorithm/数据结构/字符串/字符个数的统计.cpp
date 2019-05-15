#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s;
    while(getline(cin,s))
    {
        int fre[256]={0};
        int j=0;
        for(int i=0;i<s.size();)
        {
            if(j==s.size()){fre[i]++;i++;j=i;}
            else if(i==j)j++;
            else if(s[i]==s[j]){fre[i]++;j++;}
            else j++;
        }
        for(int i=0;i<s.size();)
        {
            if(j==i)j++;
            else if(j==s.size()){i++;j=i;}
            else if(s[i]==s[j]){fre[j]=0;j++;}
            else j++;
        }
        for(int i=0;i<256;i++)
        {
                if(fre[i]!=0)
                cout<<s[i]<<" "<<fre[i]<<endl;
        }
    }
    return 0;
}
