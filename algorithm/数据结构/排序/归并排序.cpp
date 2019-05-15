#include<iostream>
using namespace std;

void marge(int a[],int b[],int c[], int lena,int lenb)
{
    int i=0,j=0,counter=0;
    while(i<lena && j<lenb)
    {
        if(a[i]<b[j])
        {
            c[counter]=a[i];
            i++;
            counter++;
        }
        else
        {
            c[counter]=b[j];
            j++;
            counter++;
        }
    }
    while(i<lena) c[counter++]=a[i++];
    while(j<lenb) c[counter++]=b[j++];
}
void margeSort(int a[],int n)
{
    if(n>1)
    {
        int i=n/2;
        int j=n-i;
        int *b=new int[i];
        int *c=new int[j];
        for(int k=0; k<i; k++)
        {
            b[k]=a[k];
        }
        for(int k=0; k<j; k++)
        {
            c[k]=a[k+i];
        }
        margeSort(b,i);
        margeSort(c,j);
        marge(b,c,a,i,j);
    }
}
int main()
{
    int a[]= {1,3,5,4,9,6,7,8};
    int n=sizeof(a)/sizeof(int);
    margeSort(a,n);
    for(int i=0; i<n; i++)
    {
        cout<<a[i];
        if(i<n-1)cout<<" ";
    }
    return 0;
}
