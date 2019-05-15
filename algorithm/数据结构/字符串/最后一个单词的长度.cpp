#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s;
    getline(cin,s);
    int sum=0;
    for(int i=s.size()-1;i>=0;i--)
    {
        if(s[i]!=' ')sum++;
        else break;
    }
    cout<<sum<<endl;
}
