#include<iostream>
using namespace std;
int main()
{
    int **A;    //指向地址的地址
    int row=3,col=3;    //行和列
    int i,j;
    A=new int*[row];     //行地址
    for(i=0;i<row;i++)
        A[i]=new int[col];
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
            cin>>A[i][j];
    }
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
            cout<<A[i][j]<<" ";
        cout<<endl;
    }
}
