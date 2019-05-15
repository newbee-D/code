#include<iostream>
using namespace std;
int main()
{
    int a[]={1,2,3,4,5,6},*elem,i;
    for(i=0;i<6;i++)       //遍历数组
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    elem=new int[6];    // 动态数组
    //   C语言    elem=(int *)malloc(sizeof(int)*6)   内存分配
    for(i=0;i<6;i++)
    {
        cin>>elem[i];
    }
    i=0;
    while(i<6)
    {
        cout<<*elem<<" ";
        elem++;
        i++;
    }
    cout<<endl;
    return 0;
}
