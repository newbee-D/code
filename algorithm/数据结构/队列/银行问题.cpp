#include<iostream>
#include<queue>     //标准模版库
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
            B.push(x);   //压入队列
        else
            A.push(x);
    }
    while(!A.empty() && !B.empty())
    {
        x=A.front();
        C.push(x);
        A.pop();     //弹出队列
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
        x=B.front();   //取队顶元素
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
