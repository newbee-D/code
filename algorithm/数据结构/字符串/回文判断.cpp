#include<iostream>
#include<string>
using namespace std;
bool ishuiwen(string a)
{
    int first=0;
    int last=a.size()-1;
    while(first<a.size()/2)
    {
        if(a[first]==a[last])
        {
            first++;
            last--;
        }
        else {
                cout<<"This is not huiwen string ."<<endl;
                return false;
        }
    }
    cout<<"This is huiwen string ."<<endl;
    return true;
}
int main()
{
    //int n;
    string s;
    while(getline(cin,s))
    {
        /*char a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        ishuiwen(a,n);*/
        ishuiwen(s);
    }
    return 0;
}
