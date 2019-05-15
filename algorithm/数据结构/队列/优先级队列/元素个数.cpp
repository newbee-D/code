#include<iostream>
#include<queue>
using namespace std;

int main()
{
    priority_queue<int>myints;
    cout<<"0.size:"<<(int)myints.size()<<endl;
    for(int i=0; i<5; i++)myints.push(i);
    cout<<"1.size:"<<(int)myints.size()<<endl;
    myints.pop();
    cout<<"2.size:"<<(int)myints.size()<<endl;
    return 0;
}
