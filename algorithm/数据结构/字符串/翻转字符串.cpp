#include<iostream>
#include<string>
using namespace std;
int main()
{
    //int n,i;
    //cin>>n;
    //char a[n];
    string s;
    getline(cin,s);
    //for(int i=0;i<n;i++)
        //cin>>a[i];
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
    for(int i=0;i<s.size();i++)
        cout<<s[i];
    return 0;
}
