#include<iostream>
#include<algorithm>
using namespace std;
/*
�������
��Ŀ������n����Ϯ�����ĸ߶ȣ����ҷ���������ض��ٸ�
���У���һ�����ص����ĸ߶Ȳ��ɸ���ǰһ�����ص����ĸ߶ȡ�
*/

int arr[26];  //�洢�����߶���Ϣ
int F[26];      //F(i),��arr[i]��β��������

int getMax(int a,int b){ //a:�Ƚϵķ�Χ b:�Ƚϵ�ֵ
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
