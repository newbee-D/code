 #include<iostream>
#include<queue>
using namespace std;

int main()
{
    deque<int>mydeque(10);      //˫�˶���
    unsigned int i;          //�޷���������ֻ��Ϊ������������ߴ���Ч��
    for(i=0;i<mydeque.size();i++)
    {
        mydeque.at(i)=i;      //Ԫ�ش�0��ʼ
    }
    cout<<"mydeque.contains:";
    for(i=0;i<mydeque.size();i++)
        cout<<" "<<mydeque.at(i);
    cout<<endl;

    return 0;
}
