#include<iostream>
#include<stack>
using namespace std;

int main(int argc,char const*argv[])
{
    stack<int>st;
    for(int i=0;i<5;i++)
    {
        st.push(i);
    }
    cout<<"size:"<<st.size()<<endl;
    cout<<"top:"<<st.top()<<endl;
    while(!st.empty())
    {
        int a=st.top();
        cout<<a<<endl;
        st.pop();
    }
    return 0;
}
