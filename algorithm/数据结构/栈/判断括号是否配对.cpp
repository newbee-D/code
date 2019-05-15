#include<iostream>
#include<stack>
using namespace std;
class Solution
{
public:
    bool isValidParentheses(string &s)
    {
        stack<char>st;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            if(s.at(i)=='(')     //���Ϊ����ջ
            {
                st.push('(');
            }
            else if(s.at(i)==')')
            {
                if(st.empty() || st.top()!='(')
                    return false;
                else st.pop();
            }
             if(s.at(i)=='[')
            {
                st.push('[');
            }
            else if(s.at(i)==']')
            {
                if(st.empty() || st.top()!='[')
                    return false;
                else st.pop();
            }
             if(s.at(i)=='{')
            {
                st.push('{');
            }
            else if(s.at(i)=='}')
            {
                if(st.empty() || st.top()!='{')
                    return false;
                else st.pop();
            }
        }
        return st.empty();      //ջΪ��ʱ����Գɹ�����true
    }
};
int main()
{
    Solution obj;
    string s;
    getline(cin,s);      //getline()�������ڶ�ȡһ���ַ�ֱ���������з���
                   //����������һ������һ����������������ַ����ַ���
    if(obj.isValidParentheses(s))
    {
        cout<<"Yes\n";
    }
    else
        cout<<"No\n";
    return 0;
}
