#include<iostream>
#include<deque>
#include<vector>
using namespace std;

int main()
{
    deque<int>mydq;
    deque<int>::iterator it;    //����
    for(int i=0;i<6;i++)
    {
        mydq.push_back(i);
    }
    it=mydq.begin();   //ָ���һ��Ԫ��
    ++it;
    it=mydq.insert(it,10);          //����һ��10
    mydq.insert(it,2,20);     //��������20
    cout<<"1.mydq.contains:";
    for(it=mydq.begin();it<mydq.end();++it)      //end()ָ�����һ��Ԫ�ص���һ��Ԫ��
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
