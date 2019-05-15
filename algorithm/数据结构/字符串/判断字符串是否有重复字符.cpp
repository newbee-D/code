#include<iostream>
#include<string>
using namespace std;
bool iscopy(string a)
{
    int i=0;
    while(i<a.size())
    {
       for(int j=0;j<a.size();j++)
       {
           if(i==j)
            j++;
           else if(a[i]==a[j]){
            cout<<"该字符串有重复字符"<<endl;
            return true;
           }
           else j++;
       }
       i=a.size();
    }
    cout<<"该字符串没有重复的元素"<<endl;
    return false;
}
int main()
{
    /*int n;
    cin>>n;
    char a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];*/
    string s;
    getline(cin,s);
    iscopy(s);
    return 0;

}
