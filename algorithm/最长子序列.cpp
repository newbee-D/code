#include<iostream>
#include<algorithm>
using namespace std;
/*
最长子序列
题目：给出n个来袭导弹的高度，问我方最多能拦截多少个
其中：后一发拦截导弹的高度不可高于前一发拦截导弹的高度。
*/

int arr[26];  //存储导弹高度信息
int F[26];      //F(i),以arr[i]结尾的最大减序

int getMax(int a,int b){ //a:比较的范围 b:比较的值
    int res=0,m=0;
    for(int i=0;i<a;i++){
        if(arr[i]>=b){
            m=F[i];
        }
        res=max(res,m);
    }
    return res;
}

int main(){
    int n;
    while(cin>>n){
        int res=0;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            F[i]=1;
        }
        for(int i=1;i<n;i++){
            F[i]=getMax(i,arr[i])+1;
        }
        for(int i=0;i<n;i++){
            res=max(res,F[i]);
        }
        cout<<endl;
        cout<<res<<endl;
    }
    return 0;
}
