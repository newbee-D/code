#include<stdio.h>
void reverse(int a[],int n)       //基本数值
{
    int i;
    for(i=0; i<n/2; i++)
    {
        int t=a[i];
        a[i]=a[n-1-i];
        a[n-1-i]=t;
    }
}
void reverse2 (int *s,int *e)      //指针
{
    int t;
    while(s<e)
    {
        t=*s;
        *s=*e;
        *e=t;
        s++,e--;
    }
}
int main()
{
    int a[]= {1,2,3,4,5,6,7};
   
	reverse(a,7);
   
	int i;
    for(i=0; i<7; i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
   
	reverse2(a,a+6);
    
	for(i=0; i<7; i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
    return 0;
}
