#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct cmp    //方法一
{
    bool operator()(int a,int b){
        return a>b;     //最小值优先

    }
};
struct node
{
    int u;
    bool operator<(const node &a)const
    {
        return u>a.u;    //最小值优先
    }
};
int main()
{
    int a[]={3,4,2,5,7};
    int n=sizeof(a)/sizeof(int);
    vector<int>v(a,a+n);    //用静态数组构造动态数组

    priority_queue<int>p1(a,a+n);//用静态数组构造优先级队列，默认大值优先

    priority_queue<int,vector<int>,cmp>p2(a,a+n);//小值优先

    priority_queue<int,vector<int>,cmp>p3(v.begin(),v.end());//小值优先
                                                        //end()  指最后一个元素的下一个位置
    cout<<p1.top()<<endl;   //7
    cout<<p2.top()<<endl;   //2
    cout<<p2.top()<<endl;  //2
    while(!p1.empty())
    {
        cout<<p1.top()<<" ";
        p1.pop();
    }
    cout<<endl;

    while(!p2.empty())
    {
        cout<<p2.top()<<" ";
        p2.pop();
    }
    cout<<endl;

    struct node mynode;
    priority_queue<node>p4;
    for(int i=0;i<n;i++)
    {
        mynode.u=a[i];
        p4.push(mynode);
    }
    while(!p4.empty())
    {
        cout<<p4.top().u<<" ";
        p4.pop();
    }
    cout<<endl;
    return 0;

}
