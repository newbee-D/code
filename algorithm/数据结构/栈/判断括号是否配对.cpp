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
            if(s.at(i)=='(')     //如果为（入栈
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
        return st.empty();      //栈为空时，配对成功反悔true
    }
};
int main()
{
    Solution obj;
    string s;
    getline(cin,s);      //getline()函数用于读取一行字符直到遇到换行符，
                   //函数会生成一个包含一串从输入流读入的字符的字符串
    if(obj.isValidParentheses(s))
    {
        cout<<"Yes\n";
    }
    else
        cout<<"No\n";
    return 0;
}
