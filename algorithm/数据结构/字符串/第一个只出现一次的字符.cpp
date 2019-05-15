#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s;
    getline(cin,s);
    int left=0;
    int right=1;
    while(left<s.size() && right!=left)
    {
        if(right==s.size()-1)right=0;
        else {
            if(s[left]==s[right])
            {
                left++;
                right++;
            }
            else right++;
        }
    }
    cout<<s[left];
    return  0;
}
