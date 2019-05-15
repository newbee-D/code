#include<iostream>
#include<algorithm>
using namespace std;

int partition(int a[],int p,int r)
{
    int key=a[r];//ѡ���һ��Ϊ����Ԫ��
    int j=p;
    int i=p-1;//ָ���һ�������
    for(j=p; j<r; j++) //ֻѭ����r-1��λ��
    {
        if(a[j]<=key)
        {
            i++;
            swap(a[i],a[j]);
        }
    }
        swap(a[i+1],a[r]);
        return i+1;//���ػ���λ��

}
void quick_sort(int a[],int p,int r)
{
    if (p<r)
    {
        int q = partition (a, p, r) ;	//���ջ���Ԫ�ص�����λ��
        quick_sort (a, p, q-1);	//�Ի��ֵ������н��еݹ����
        quick_sort(a,q+1,r);
    }
}

int main()
{
    int a[]= {11,22,55,4,5,65,7,4,8};
    int n=sizeof(a)/sizeof(int);
    quick_sort(a,0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<a[i];
        if(i<n-1)cout<<" ";
    }
    return 0;
}
