#include<iostream>
#include<deque>
#include<vector>
using namespace std;

int main()
{
    deque<int>mydq;
    deque<int>::iterator it;    //迭代
    for(int i=0;i<6;i++)
    {
        mydq.push_back(i);
    }
    it=mydq.begin();   //指向第一个元素
    ++it;
    it=mydq.insert(it,10);          //插入一个10
    mydq.insert(it,2,20);     //插入两个20
    cout<<"1.mydq.contains:";
    for(it=mydq.begin();it<mydq.end();++it)      //end()指向最后一个元素的下一个元素
        cout<<" "<<*it;
    cout<<endl;

    it=mydq.begin()+2;
    vector<int>v(2,30);
    mydq.insert(it,v.begin(),v.end());
    cout<<"2.mydq.contains:";
    for(it=mydq.begin();it<mydq.end();++it)
        cout<<" "<<*it;
    cout<<endl;
    return 0;
}
