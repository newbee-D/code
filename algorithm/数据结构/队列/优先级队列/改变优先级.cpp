#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct cmp    //����һ
{
    bool operator()(int a,int b){
        return a>b;     //��Сֵ����

    }
};
struct node
{
    int u;
    bool operator<(const node &a)const
    {
        return u>a.u;    //��Сֵ����
    }
};
int main()
{
    int a[]={3,4,2,5,7};
    int n=sizeof(a)/sizeof(int);
    vector<int>v(a,a+n);    //�þ�̬���鹹�춯̬����

    priority_queue<int>p1(a,a+n);//�þ�̬���鹹�����ȼ����У�Ĭ�ϴ�ֵ����

    priority_queue<int,vector<int>,cmp>p2(a,a+n);//Сֵ����

    priority_queue<int,vector<int>,cmp>p3(v.begin(),v.end());//Сֵ����
                                                        //end()  ָ���һ��Ԫ�ص���һ��λ��
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
