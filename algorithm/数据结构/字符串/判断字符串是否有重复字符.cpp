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
            cout<<"���ַ������ظ��ַ�"<<endl;
            return true;
           }
           else j++;
       }
       i=a.size();
    }
    cout<<"���ַ���û���ظ���Ԫ��"<<endl;
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
