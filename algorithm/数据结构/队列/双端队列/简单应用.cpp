 #include<iostream>
#include<queue>
using namespace std;

int main()
{
    deque<int>mydeque(10);      //双端队列
    unsigned int i;          //无符号整数，只能为正数，具有最高处理效率
    for(i=0;i<mydeque.size();i++)
    {
        mydeque.at(i)=i;      //元素从0开始
    }
    cout<<"mydeque.contains:";
    for(i=0;i<mydeque.size();i++)
        cout<<" "<<mydeque.at(i);
    cout<<endl;

    return 0;
}
