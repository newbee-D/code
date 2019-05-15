#include<iostream>
#include<vector>
using namespace std;
class Printer
 {
 public:
    vector<int> clockwisePrint(vector<vector<int> >mat,int n,int m)
    {
        vector<int> result;
        int flag=0;
        int upperRow=0;
        int bottomRow=n-1;
        int leftCol=0;
        int rightCol=m-1;
        int i=0,j=0;
        for(int k=0;k<=n*m;k++)
        {
            result.push_back(mat[i][j]);
            if(flag==0){
                    if(i+1<=bottomRow) i++;
                    else{j--;flag=1;rightCol=i;}
            }
            else if(flag==1)
            {
                if(j+1<=rightCol) j++;
                else {i++;flag=2;upperRow=j;}
            }
            else if(flag==2){
                if(j-1>=upperRow) j--;
                else{i++;flag=3;leftCol=i;}
            }
            else if(flag==3){
                if(i-1>=leftCol) i--;
                else{j--;flag=0;bottomRow=i;}
            }
        }
        return result;
    }
 };
 int main()
 {
     int a[4][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
     int row=4;
     int col=4;
     vector<vector<int> >mat(row,vector<int> (col));
     vector<int>result;
     for(int i=0;i<row;i++){
        for(int j=0;j<col;j++)
            mat[i][j]=a[i][j];
     }
        Printer obj;
        result=obj.clockwisePrint(mat,row,col);
        for(int i=0;i<result.size();i++)
        {
            cout<<result[i];
            if(i<result.size()-1)cout<<" ";
        }
        cout<<endl;
        return 0;
 }

