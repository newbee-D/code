#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int a[11]={2,5,8,6};
	int b[]={1,2,3,5,6,4,7};
	sort(a,a+4);      //ÉýÐò
	sort(b,b+7);
	int i,j;
	for(i=0; i<4; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    for(j=0; j<7; j++)
    {
        cout<<b[j]<<" ";
    }
    cout<<endl;
	i=3,j=6;
	int k=10;
	for(;i>=0 && j>=0;k--)
	{
		int xa=a[i];
		int xb=b[j];
		if(xa>=xb)
		{
			a[k]=a[i];
			i--;
		}
		else
		{
			a[k]=b[j];
			j--;
		}
	}
	while (j>=0)
	{
		a[k]=b[j];
		j--,k--;
	}
	for(i=0; i<11; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
	return 0;
}
