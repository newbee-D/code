#include<iostream>
#include<stack>
using namespace std;
const int maxn=1000;
int arr[maxn];
stack<int>st;    //��׼ģ���
int main(int argc,char const argv[])
{
    int m,n,k;      //mջ����  nջԪ�ظ��� k�����ջ˳�����
    cin>>m>>n>>k;
    while(k--)
    {
        while(!st.empty())
        {
            st.pop();    //���ջ
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
            if(st.size()>m)    //���ջ��Ԫ�ظ�������m  ���зǷ�
            {
                flag=false;
                break;
            }
            while(!st.empty()&&st.top()==arr[cur])//���ջ��Ԫ�ص��ڳ�ջ���е�ǰλ��Ԫ��
            {
                st.pop();                 //������ջ
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
