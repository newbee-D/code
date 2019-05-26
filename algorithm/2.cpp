#include<iostream>
using namespace std;

int main(){
    int a[3];
    int b[3];
    int arr[14];
    for(int i=0;i<14;i++){
        arr[i]=4;
    }
    for(int i=0;i<3;i++){
        cin>>a[i];
        arr[a[i]]--;
    }
    for(int i=0;i<3;i++){
        cin>>b[i];
        arr[b[i]]--;
    }
    double res=0.000;
    if((a[0]+a[1]+a[2])-(b[0]+b[1]+b[2])>11){
        res=1.000;
    }else if((b[0]+b[1]+b[2])-(a[0]+a[1]+a[2])>11){
        res=0.000;
    }else{

    }
    cout<<res<<endl;
    return 0;
}
