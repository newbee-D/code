#include<iostream>
using namespace std;
int arr[1000][1000]={0};
int main(){
    int n;cin>>n;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        arr[x][y]=1;
    }
    int m;cin>>m;
    while(m--){
        int a1,b1,a2,b2;
        int res=0;
        cin>>a1>>b1>>a2>>b2;
        for(int i=a1;i<=a2;i++){
            for(int j=b1;j<=b2;j++){
                if(arr[i][j]==1){
                    res++;
                }
            }
        }
        cout<<res<<endl;
    }
    return 0;
}
