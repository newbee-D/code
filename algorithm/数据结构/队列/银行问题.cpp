#include<iostream>
#include<queue>     //��׼ģ���
using namespace std;
int main(int argc,char const*argv[])
{
    queue<int>A;
    queue<int>B;
    queue<int>C;
    int n,x;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>x;
        if(x%2==0)
            B.push(x);   //ѹ�����
        else
            A.push(x);
    }
    while(!A.empty() && !B.empty())
    {
        x=A.front();
        C.push(x);
        A.pop();     //��������
        if(!A.empty())
        {
            x=A.front();
            C.push(x);
            A.pop();
        }
        x=B.front();
        C.push(x);
        B.pop();
    }
    while(!A.empty())
    {
        x=A.front();
        C.push(x);
        A.pop();
    }
    while(!B.empty())
    {
        x=B.front();   //ȡ�Ӷ�Ԫ��
        C.push(x);
        B.pop();

    }
    bool first=true;
    while(!C.empty())
    {

        if(first)
        {
            cout<<C.front();
            first=false;
            C.pop();
        }
        else{
            cout<<" "<<C.front();
            C.pop();
        }
    }
    cout<<endl;
    return 0;
}
