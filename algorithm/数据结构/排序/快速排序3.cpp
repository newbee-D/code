#include<iostream>
#include<algorithm>
using namespace std;

int partition(int a[],int p,int r)
{
    int key=a[r];//选最后一个为划界元素
    int j=p;
    int i=p-1;//指向第一个的左边
    for(j=p; j<r; j++) //只循环到r-1的位置
    {
        if(a[j]<=key)
        {
            i++;
            swap(a[i],a[j]);
        }
    }
        swap(a[i+1],a[r]);
        return i+1;//返回化解位置

}
void quick_sort(int a[],int p,int r)
{
    if (p<r)
    {
        int q = partition (a, p, r) ;	//返冋划界元素的最终位置
        quick_sort (a, p, q-1);	//对划分的子序列进行递归操作
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
