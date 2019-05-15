#include<iostream>
#include<stack>
using namespace std;
const int maxn=1000;
int arr[maxn];
stack<int>st;    //标准模版库
int main(int argc,char const argv[])
{
    int m,n,k;      //m栈容量  n栈元素个数 k输入出栈顺序次数
    cin>>m>>n>>k;
    while(k--)
    {
        while(!st.empty())
        {
            st.pop();    //清空栈
        }
        for(int i=1; i<=n; i++)
        {
            cin>>arr[i];
        }
    }
        int cur=1;
        bool flag=true;
        for(int j=1; j<=n; j++)
        {
            st.push(j);
            if(st.size()>m)    //如果栈中元素个数大于m  序列非法
            {
                flag=false;
                break;
            }
            while(!st.empty()&&st.top()==arr[cur])//如果栈顶元素等于出栈序列当前位置元素
            {
                st.pop();                 //反复出栈
                cur++;
            }
        }
        if(st.empty() && flag==true)
        {
            cout<<"Yes"<<endl;
        }
        else
        {
            cout<<"No"<<endl;
        }
    return 0;
}
