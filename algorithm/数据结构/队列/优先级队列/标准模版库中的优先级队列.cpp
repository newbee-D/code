#include<iostream>
#include<queue>
using namespace std;
int main()
{
    priority_queue<int>mypq;
    mypq.push(30);
    mypq.push(100);
    mypq.push(20);
    mypq.push(50);
    cout<<"Popping out elements ..."<<endl;
    while(!mypq.empty())
    {
        cout<<" "<<mypq.top();  //模版库函数默认数越大优先级越高
        mypq.pop();
    }
    cout<<endl;
    return 0;
}
