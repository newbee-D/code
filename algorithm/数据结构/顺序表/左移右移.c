 #include<stdio.h>
int main()
{
    int a[]={1,2,4,5,6,7,9,8};
    int k=2,n=8;
    int j,i;
    for(j=1;j<=k;j++)
    {
        int t=a[n-1];
        for(i=n-2;i>=0;i--)
        {
            a[i+1]=a[i];
        }
            a[0]=t;

    }
    i=0;
    for(i=0;i<8;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
    for(j=1;j<=k;j++)
    {
        int t=a[0];
        for(i=1;i<n;i++)
        {
            a[i-1]=a[i];
        }
        a[n-1]=t;
    }
     i=0;
    for(i=0;i<8;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");

    return 0;
}
