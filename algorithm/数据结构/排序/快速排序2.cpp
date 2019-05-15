#include<iostream>
#include<algorithm>
using namespace std;

void printArray(int a[],int p,int r)
{
    for(int i=p; i<r; i++)
    {
        cout<<a[i];
        if(i<r-1)cout<<" ";
    }
    cout<<endl;
}
int partition(int a[],int p,int r)
{
    int key=a[p];//�Ե�һ��Ԫ��Ϊ����Ԫ��
    int i=p;
    int j=r+1;//ָ�����ұ���һ��Ԫ��
    while(i<j)
    {
        while(a[++i]<key && i<r);
        while(a[--j]>key);
        if(i<j)
        {
            swap(a[i],a[j]);
        }
    }
    a[p]=a[j];
    a[j]=key;
    return j;
}
void quick_sort(int a[],int p,int r)
{
    if (p<r)
    {
        int q = partition (a, p, r);	//���ջ���Ԫ�ص�����λ��
        printArray(a,p,q-1);
        printArray(a,q+1,r);
        quick_sort (a,p,q-1);	//�Ի��ֵ������н��еݹ����
        quick_sort(a,q+1,r);
    }
}
int main()
{
    int a[]= {11,22,55,4,5,65,7,4,8};
    int n=sizeof(a)/sizeof(int);
    quick_sort(a,0,n-1);
    for(int i=0; i<n; i++)
    {
        cout<<a[i];
        if(i<n-1)cout<<" ";
    }
    return 0;
}
/*�㷨˼��
p             r
4 1 5 6 3 6 2 7
i              j=r+1*/
