#include<iostream>
using namespace std;
int main()
{
    int **A;    //ָ���ַ�ĵ�ַ
    int row=3,col=3;    //�к���
    int i,j;
    A=new int*[row];     //�е�ַ
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
